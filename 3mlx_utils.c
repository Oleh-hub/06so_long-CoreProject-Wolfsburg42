/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3mlx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:32:57 by oruban            #+#    #+#             */
/*   Updated: 2024/03/22 19:48:39 by oruban           ###   ########.fr       */
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
static void	check_exit(t_frame *game)
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

void	move_player(t_frame *game, int x, int y)
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

void	move_a_d(int keycode, t_frame *game)
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

// putting all images to mlx window - initiating the map
void	init_map(t_frame *game)
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
