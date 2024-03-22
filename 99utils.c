/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:34 by oruban            #+#    #+#             */
/*   Updated: 2024/03/22 16:29:30 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// puts the images that change its position/ dissapear or appear
// 2 the window again

void static	change_positioin(t_frame *game, int x, int y)
{
	if (game->lastpos == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->floor, game->player[1] * PIC_SIZE, \
			game->player[0] * PIC_SIZE);
	else if (game->lastpos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->door[0], game->player[1] * PIC_SIZE, \
			game->player[0] * PIC_SIZE);
	game->map[game->player[0]][game->player[1]] = game->lastpos;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, \
		x * PIC_SIZE, y * PIC_SIZE);
	game->lastpos = game->map[y][x];
	game->player[0] = y;
	game->player[1] = x;
	game->steps++;
	ft_printf("steps: %i\tCollectibles: %i/%i\n", game->steps, game->collected, \
		game->collectibles);
}

// finds the 'E'xit coordinates and cchanges the 'E'xit door sprite if all 
// 'C'ollectibles are collected
void	check_exit(t_frame *game)
{
	int	x;
	int	y;

	y = -1;
	if (game->collectibles == game->collected)
	{
		while (++y < game->rows)
		{
			x = -1;
			while (++x < game->cols)
				if (game->map[y][x] == 'E')
					mlx_put_image_to_window(game->mlx, game->mlx_win, \
						game->door[1], x * PIC_SIZE, y * PIC_SIZE);
		}
	}
}

static void	move_player(t_frame *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x] = '0';
			game->collected++;
			check_exit(game);
		}
		change_positioin(game, x, y);
	}
	else if (game->map[y][x] == 'E' && game->collectibles != game->collected)
	{
		ft_printf("The collectibls are still there!\n");
		change_positioin(game, x, y);
	}
	else
	{
		change_positioin(game, x, y);
		ft_printf("CNOGRATULATION! YOU HAVE WON!\n");
		exit(0);
	}
}

// function calles for mlx_put_image_to_window() in compact way,
// 2 allow such funcitons as init_map() and move_a_d() to have 
// less then 25 lines
void	shrt_img2win(t_frame *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, \
		x * PIC_SIZE, y * PIC_SIZE);
}

static void	move_a_d(int keycode, t_frame *game)
{
	if (keycode == KEY_A)
	{
		if (game->direction != 'L')
		{
			game->player_img = game->player_sprite[1];
			shrt_img2win(game, game->player_img, game->player[1], \
				game->player[0]);
			game->direction = 'L';
		}
		else
			move_player(game, game->player[1] - 1, game->player[0]);
	}
	else if (keycode == KEY_D)
	{
		if (game->direction != 'R')
		{
			game->player_img = game->player_sprite[0];
			shrt_img2win(game, game->player_img, game->player[1], \
				game->player[0]);
			game->direction = 'R';
		}
		else
			move_player(game, game->player[1] + 1, game->player[0]);
	}
}

// handling event KeyPress 02 of mlx_hook()
// movement at left A, at right D, above W, downwards S
int	key_hook(int keycode, t_frame *game)
{
	if (keycode == ESC_KEY)
		correct_exit(game);
	else if (keycode == KEY_A || keycode == KEY_D)
		move_a_d(keycode, game);
	else if (keycode == KEY_W)
		move_player(game, game->player[1], game->player[0] - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player[1], game->player[0] + 1);
	return (0);
}

// just a correct freeing the potantial memory leaks when the 
// window of project is closed:
// 1 - destoying all images created for *mlx_win with 'mlx_xpm_file_to_image()'
// 2 - destroying  this *mlx_win window
// 3 - freeing everythng allocated in form 't_frame *gane'
// 4 - freeing game 't_frame *game' itself
//
// free(game->mlx); // should free mem alloced by mlx_init() but itdoes not!
int	correct_exit(t_frame *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->player_sprite[0]);
	mlx_destroy_image(game->mlx, game->player_sprite[1]);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->door[0]);
	mlx_destroy_image(game->mlx, game->door[1]);
	mlx_destroy_window(game->mlx, game->mlx_win);
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	free(game);
	exit(0);
}

// closes open mam file and fees memory allocated by gnl, 
// if fd > 0 and str != NULL 
void	error_exit(const char *message, int fd, char *line1, char *line2)
{
	if (fd > 0)
		close (fd);
	if (!line1)
		free (line1);
	if (!line2)
		free (line2);
	write (2, message, ft_strlen(message));
	exit (1);
}
