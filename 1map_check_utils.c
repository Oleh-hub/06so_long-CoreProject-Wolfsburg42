/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1map_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:23:38 by oruban            #+#    #+#             */
/*   Updated: 2024/03/24 21:31:20 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* checking if map has only 1 'P' and 'E', > 0 'C' and '0', '1' at start
 and begining and is == cols */
t_peco	*ismiddle(char *line, char *next_l, int cols, int fd)
{
	static t_peco	peco = {0, 0, 0, 0, 0};
	t_func_pars		chr_chck;

	chr_chck.line = line;
	chr_chck.next_l = next_l;
	chr_chck.cols = cols;
	chr_chck.fd = fd;
	if (line[0] != '1' || line[cols - 1] != '1')
		error_exit("Error: surround map by '1'\n", fd, line, next_l);
	chr_chck.cols--;
	while ((line[chr_chck.cols] >= 0) && (line[chr_chck.cols] == '0'
			|| line[chr_chck.cols] == 'P' || line[chr_chck.cols] == 'E'
			|| line[chr_chck.cols] == 'C' || line[chr_chck.cols] == '1'))
	{
		peco_chrs_chck(&peco, chr_chck);
		chr_chck.cols--;
	}
	if (chr_chck.cols >= 0)
		error_exit("Error: map must be only '0PEC1' chars\n", fd, line, next_l);
	return (&peco);
}

// check if the char *s is a wall (consists only of '1' chars)
int	iswall(char *s, char flag, int fd)
{
	int	i;
	int	map_len;

	if (flag == 'l')
		map_len = ft_strlen(s);
	else
		map_len = ft_strlen(s) - 1;
	i = 0;
	while (i < map_len)
	{
		if (s[i] != '1')
		{
			if (flag == 'l')
				ft_printf("Error: last line of map has a non '1' character\n");
			error_exit("Error: map has non '1' chars\n", fd, s, NULL);
		}
		i++;
	}
	if (flag != 'l' && s[i] != '\n')
		error_exit("Error: check the walls\n", fd, s, NULL);
	return (i);
}

// check if the map is a rectangler and colls for check of middle lins of maps
static t_peco	*map_valid_sub(t_frame *game, t_func_pars *to_free, t_peco \
*peco, int fd)
{
	char	*line_trimmed;
	char	*next_l_trimmed;

	line_trimmed = ft_strtrim(to_free->line, "\n");
	next_l_trimmed = ft_strtrim(to_free->next_l, "\n");
	if (ft_strlen(line_trimmed) != ft_strlen(next_l_trimmed))
	{
		free(line_trimmed);
		free(next_l_trimmed);
		error_exit("Error: map must be a rectangle\n", fd, \
		to_free->line, to_free->next_l);
	}
	free(line_trimmed);
	free(next_l_trimmed);
	peco = ismiddle(to_free->line, to_free->next_l, game->cols, fd);
	free(to_free->line);
	to_free->line = to_free->next_l;
	game->rows++;
	to_free->next_l = get_next_line(fd);
	return (peco);
}

/* validates the entire content of map,
sets value to game->cols and game->rows
PARAMETERS 
int		fd - map file discriptor,
t_frame	*game - pointer at the map structure, game->rows 2 b filled 
RETURNs
the number of map rows if validation passes or 0 if not */
int	map_valid(int fd, t_frame *game)
{
	t_peco		*peco;
	t_func_pars	*to_free;

	to_free = (t_func_pars *)malloc(sizeof(t_func_pars));
	if (!to_free)
		error_exit("Error: memory allocation fail\n", fd, NULL, NULL);
	to_free->line = get_next_line(fd);
	game->cols = iswall(to_free->line, ' ', fd);
	free(to_free->line);
	to_free->line = get_next_line(fd);
	to_free->next_l = get_next_line(fd);
	game->rows = 2;
	while (to_free->next_l)
		peco = map_valid_sub(game, to_free, peco, fd);
	if ((!peco->c) || !peco->o || !peco->p || !peco->e)
		error_exit("Error: map must have min 1 'C0EP'\n", fd, to_free->line, \
			to_free->next_l);
	if (game->cols != iswall(to_free->line, 'l', fd))
		error_exit("Error: 1st wall line != last one\n", fd, to_free->line, \
			NULL);
	free(to_free->line);
	free(to_free);
	return (game->rows);
}

void	init_frame_start(t_frame *game)
{
	game->rows = 0;
	game->cols = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->steps = 0;
	game->collected = 0;
}
