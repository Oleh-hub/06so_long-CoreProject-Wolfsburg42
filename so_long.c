/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/20 15:10:16 by oruban           ###   ########.fr       */
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

static void	load_wiz_collectables(t_frame game)
{
	(void) game;
}

// the works with minilibx for mac starts here
// plz note that during map parcing [rows][cols] (y,x) were used but now:
// [cols][rows] (x,y) !
static void	start_mlx(t_frame *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, PIC_SIZE * game->cols, \
		PIC_SIZE * game->rows, "so_long project");
	game->lastpos = '0';
	load_wiz_collectables(game);
}

/* checks the map.name and calls for map_valid that checks the map content */
static t_frame	*map_check(char *av)
{
	t_frame	*game;
	char	*ext;
	int		fd;

	ext = ft_strrchr(av, '.');
	if (!ext || ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
		error_exit("Error: map name is to be '*.ber' format\n", -1, NULL, NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_exit("Error: map file cannot be open\n", -1, NULL, NULL);
	game = (t_frame *)ft_calloc(1, sizeof(t_frame));
	if (!game)
		error_exit("Error: Memory allocation failed\n", fd, NULL, NULL);
	init_frame_start(game);
	if (!map_valid(fd, game))
		ft_printf("map %s is not valid :)\n", av);
	fd = open(av, O_RDONLY);
	init_frame_map(game, fd);
	is_path(game);
	return (game);
}

int	main(int ac, char **av)
{
	t_frame	*game;
	int		i;

	if (ac != 2)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	game = map_check(av[1]);
	ft_printf("!!!=======work with mlx starts here!\n"); //
	start_mlx(game);
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	free(game);
	return (0);
}
