/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/12 20:09:37 by oruban           ###   ########.fr       */
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

static bool map_valid(int fd, t_frame *game)
{
	char *line;
	(void) game;
	
	line = get_next_line(fd);
	printf("%s\n", line);
	
	return (true);
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

static void	error_exit(const char *s)
{
	write (2, s, ft_strlen(s));
	exit (1);
}

static t_frame	*map_check(char *av)
{
	t_frame	*game;
	char	*ext;
	int		fd;

	ext = ft_strrchr(av, '.');
	if (!ext || ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
		error_exit("Error: name of the map should be of '*.ber' format\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_exit("Error: map file cannot be open\n");
	game = (t_frame *)malloc(sizeof(t_frame));
	if (!game)
	{
		close(fd);
		error_exit("Error: Memory allocation failed\n");
	}
	init_frame(game);
	if (!map_valid(fd, game))
		ft_printf("map %s is not valid\n", av);
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
