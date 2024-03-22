/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/22 08:33:29 by oruban           ###   ########.fr       */
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

// putting all images to mlx window - initiating the map
static void	init_map(t_frame *game)
{
	int	col;
	int	row;

	col = -1;
	while (++col < game->cols)
	{
		row = -1;
		while (++row < game->rows)
		{
			if (game->map[row][col] == '1')
				shrt_img2win(game, game->wall, col, row);
			if (game->map[row][col] == '0')
				shrt_img2win(game, game->floor, col, row);
			if (game->map[row][col] == 'C')
				shrt_img2win(game, game->collectible, col, row);
			if (game->map[row][col] == 'P')
				shrt_img2win(game, game->player_img, col, row);
			if (game->map[row][col] == 'E')
				shrt_img2win(game, game->door[0], col, row);
		}
	}
}

// reads images of wall, floor, 2 images of door (closed[0] and open[1])
static void	read_walls_door(t_frame *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/wall.xpm", &game->img_side, &game->img_side);
	game->floor = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/floor.xpm", &game->img_side, &game->img_side);
	game->door[0] = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/door0.xpm", &game->img_side, &game->img_side);
	game->door[1] = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/door1.xpm", &game->img_side, &game->img_side);
}

// reads images of 'P'layer right[0] and left[1] and 'C'ollectible
// and sets the left or right turn player image depanding on 
// starting map position.
static void	read_player_cllctbls(t_frame *game)
{
	game->collectible = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/collectible.xpm", &game->img_side, &game->img_side);
	game->player_sprite[0] = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/player_right.xpm", &game->img_side, &game->img_side);
	game->player_sprite[1] = mlx_xpm_file_to_image(game->mlx, \
			"./imgs/xpm/player_left.xpm", &game->img_side, &game->img_side);
	if (game->player[1] <= game->cols / 2)
	{
		game->player_img = game->player_sprite[0];
		game->direction = 'R';
	}
	if (game->player[1] > game->cols / 2)
	{
		game->player_img = game->player_sprite[1];
		game->direction = 'L';
	}
}

// the works with minilibx for mac starts here
// plz note that during map parcing [rows][cols] (y,x) were used but now:
// [cols][rows] (x,y) !
//
// mlx_hook(game->mlx_win, 2, 1L << 0, ft_key_hook, game);
//==========================================================
// PARAMETERS: 
// '2' - event a key is been pressed, 
// '1L << 0' - means that the handler funciton 'ft_key_hook 'should be
// executed b4 next events
// mlx_hook(game->mlx_win, 17, 1L << 2, free_destroy, game);
//==========================================================
// PARAMETERS: 
// '17' - window close event, 
// '1L << 2' -event mask 1L << 2 indicates that the hook function
//  should be called after other events. 
static void	start_mlx(t_frame *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, PIC_SIZE * game->cols, \
		PIC_SIZE * game->rows, "so_long project");
	game->lastpos = '0';
	read_player_cllctbls(game);
	read_walls_door(game);
	init_map(game);
	ft_printf("Steps: %i\tHerbs: %i/%i\n", game->steps, game->collectibles, \
		game->collected);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, correct_exit, game);
	mlx_loop(game->mlx);
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

	if (ac != 2)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	game = map_check(av[1]);
	start_mlx(game);
	return (0);
}
