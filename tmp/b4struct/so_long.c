/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/18 11:30:39 by oruban           ###   ########.fr       */
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

/* checking if map has only 1 'P' and 'E', > 0 'C' and '0', '1' at start
 and begining and is == cols */
void	ismiddle(char *line, char *next_l, int cols, int fd)
{
	static int	p = 0;
	static int	e = 0;
	static int	c = 0;
	static int	o = 0;

	if (line[0] != '1' || line[cols - 1] != '1')
		error_exit("Error: surround map by '1'\n", fd, line, next_l);
	cols--;
	while (line[cols] && (line[cols] == '0' || line[cols] == 'P'
			|| line[cols] == 'E' || line[cols] == 'C' || line[cols] == '1'))
	{
		if (line[cols] == 'P')
		{
			if (p > 1)
				error_exit("Error: let map have 1 'P'\n", fd, line, next_l);
			p++;
		}
		if (line[cols] == 'E')
		{
			if (e > 1)
				error_exit("Error: let map have 1 'E'\n", fd, line, next_l);
			e++;
		}
		if (line[cols] == 'C')
			c++;
		if (line[cols] == '0')
			o++;
		cols--;
	}
	if (cols >= 0)
		error_exit("Error: let map has 1 '0PEC1' chars\n", fd, line, next_l);
	if (!c || !o)
		error_exit("Error: map must have min 1 'C' & '0'\n", fd, line, next_l);
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
			error_exit("Error: map has non 1 chars\n", fd, s, NULL);
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

	line = get_next_line(fd);
	game->cols = iswall(line, ' ', fd);
	free(line);
	line = get_next_line(fd);
	next_l = get_next_line(fd);
	while (next_l)
	{
		ismiddle(line, next_l, game->cols, fd);
		free(line);
		line = next_l;
		next_l = get_next_line(fd);
	}
	if (game->cols != iswall(line, 'l', fd))
		error_exit("Error: 1st wall line != last one\n", fd, line, NULL);
	free(line);
	close(fd);
	return (game->rows);
}

static void	init_frame(t_frame *game)
{
	game->rows = 0;
	game->cols = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->steps = 0;
	game->collected = 0;
}

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
	init_frame(game);
	if (!map_valid(fd, game))
		ft_printf("map %s is not valid :)\n", av);
	else
		ft_printf("int fd = %i, t_frame *game = %p\n", fd, game);
	close(fd);
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
