/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:34 by oruban            #+#    #+#             */
/*   Updated: 2024/03/21 20:18:09 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_a_d(int keycode, t_frame *game)
{
	if (keycode == KEY_A)
	{
		
	}
	else if (keycode == KEY_D)
	{
		
	}
}

// handling event KeyPress 02 of mlx_hook()
int	key_hook(int keycode, t_frame *game)
{
	if (keycode == ESC_KEY)
		correct_exit(game);
	else if (keycode == KEY_A || keycode == KEY_D)
		move_a_d(keycode, game);
	else if (keycode == KEY_W)
		;
	else if (keycode == KEY_S)
		;
	return (0);
}

// just a correct freeing the potantial memory leaks when the 
// window of project is closed:
// 1 - destoying all images created for *mlx_win with 'mlx_xpm_file_to_image()'
// 2 - destroying  this *mlx_win window
// 3 - freeing everythng allocated in form 't_frame *gane'
// 4 - freeing game 't_frame *game' itself
int	correct_exit(t_frame *game)
{
	int i;

	mlx_destroy_image(game->mlx, game->collectible); // frees allocated by mlx_xpm_file_to_image()
	mlx_destroy_image(game->mlx, game->player_sprite[0]);
	mlx_destroy_image(game->mlx, game->player_sprite[1]);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->door[0]);
	mlx_destroy_image(game->mlx, game->door[1]);
	mlx_destroy_window(game->mlx, game->mlx_win); // frees created by mlx_new_window()
	// mlx_destroy_display(game->mlx); // Correct method to free MiniLibX connection by chatgpt
	// free(game->mlx); 	// frees allocated by mlx_init();
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
