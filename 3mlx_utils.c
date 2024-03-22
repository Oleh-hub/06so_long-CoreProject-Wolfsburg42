/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3mlx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:32:57 by oruban            #+#    #+#             */
/*   Updated: 2024/03/22 18:35:59 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
