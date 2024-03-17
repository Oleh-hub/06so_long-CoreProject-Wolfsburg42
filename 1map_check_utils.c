/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:23:38 by oruban            #+#    #+#             */
/*   Updated: 2024/03/17 18:27:46 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	peco_chrs_chck(t_peco *peco, t_func_pars chr_chck)
{
	if (chr_chck.line[chr_chck.cols] == 'P')
	{
		if (peco->p >= 1)
			error_exit("Error: let map have 1 'P'\n", chr_chck.fd,
				chr_chck.line, chr_chck.next_l);
		peco->p++;
	}
	if (chr_chck.line[chr_chck.cols] == 'E')
	{
		if (peco->e >= 1)
			error_exit("Error: let map have 1 'E'\n", chr_chck.fd,
				chr_chck.line, chr_chck.next_l);
		peco->e++;
	}
	if (chr_chck.line[chr_chck.cols] == 'C')
		peco->c++;
	if (chr_chck.line[chr_chck.cols] == '0')
		peco->o++;
	if (chr_chck.line[chr_chck.cols] == '1')
		peco->l++;
}

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
				ft_printf("Here should be the extra mem leaks lequedation\n");
			error_exit("Error: map has non '1' chars\n", fd, s, NULL);
		}
		i++;
	}
	if (flag != 'l' && s[i] != '\n')
		error_exit("Error: wall has not allowed chars\n", fd, s, NULL);
	return (i);
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
	char	*line;
	char	*next_l;
	t_peco	*peco;

	line = get_next_line(fd);
	game->cols = iswall(line, ' ', fd);
	free(line);
	line = get_next_line(fd);
	next_l = get_next_line(fd);
	game->rows = 2;
	while (next_l)
	{
		peco = ismiddle(line, next_l, game->cols, fd);
		free(line);
		line = next_l;
		game->rows++;
		next_l = get_next_line(fd);
	}
	if ((!peco->c) || !peco->o || !peco->p)
		error_exit("Error: map must have min 1 'C0P'\n", fd, line, next_l);
	if (game->cols != iswall(line, 'l', fd))
		error_exit("Error: 1st wall line != last one\n", fd, line, NULL);
	free(line);
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
