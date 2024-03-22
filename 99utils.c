/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:34 by oruban            #+#    #+#             */
/*   Updated: 2024/03/22 19:50:58 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function calles for mlx_put_image_to_window() in compact way,
// 2 allow such funcitons as init_map() and move_a_d() to have 
// less then 25 lines
void	shrt_img2win(t_frame *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, \
		x * PIC_SIZE, y * PIC_SIZE);
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

// checks if the mapfile.ber has at least 1 'P', 1 'E' and counts 'C', '0' 
// and '1's
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
