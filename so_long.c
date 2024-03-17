/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/17 18:04:54 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// minilibx_opengl.tgz is unpacked into .\minilibx_macos
// scholarship timetable: https://42wolfsburgberlin.notion.site/Timeline-
// November-2023-Kick-off-718cb5c4a4884321b9a954ed04b01ba1
// https://github.com/jotavare/42-resources?tab=readme-ov-file#02-so_long
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long
// https://www.youtube.com/watch?v=D1DeE-Qit3M&t=17s

// check of the functions used:
// Nm -r ./so_long

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

static int	iswall(char *s, char flag, int fd)
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
static int	map_valid(int fd, t_frame *game)
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

static void	init_frame_start(t_frame *game)
{
	game->rows = 0;
	game->cols = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->steps = 0;
	game->collected = 0;
}

/* checks the map.name and calls for map_valid that checks the map content */
static t_frame	*map_check(char *av)
{
	t_frame	*game;
	char	*ext;
	int		fd;

	ext = ft_strrchr(av, '.');
	if (!ext || ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
		error_exit("Error: map name should be '*.ber' format\n", 0, NULL, NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_exit("Error: map file cannot be open\n", 0, NULL, NULL);
	game = (t_frame *)malloc(sizeof(t_frame));
	if (!game)
		error_exit("Error: Memory allocation failed\n", fd, NULL, NULL);
	init_frame_start(game);
	if (!map_valid(fd, game))
		ft_printf("map %s is not valid :)\n", av);
	ft_printf("The map %s int is valid full ini of t_frame *game and check of path to b follwed\n", av); //
	// init_frame_finish(game);
	
	close(fd);
	// is_path(game);
	return (game);
}

int	main(int ac, char **av)
{
	t_frame	*game;

	if (ac != 2)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	game = map_check(av[1]);
	free(game);
	return (0);
}
