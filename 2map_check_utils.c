/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2map_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:00:34 by oruban            #+#    #+#             */
/*   Updated: 2024/03/28 09:24:12 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks if 'P' can reach 'E' and collect all 'C'
// via comparition the position of P and E on the map with 
// marked value. If the last == 0 -> the E or C is not reachable for the Player.
void	check_path(t_frame *game, int **marked)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if ((game->map[i][j] == 'E' && !marked[i][j]) ||
				(game->map[i][j] == 'C' && !marked[i][j]))
			{
				i = -1;
				while (++i < game->rows)
				{
					free(game->map[i]);
					free(marked[i]);
				}
				free(game->map);
				free(marked);
				error_exit("Error: E or C is not reachable\n", -1, NULL, NULL);
			}
		}
	}
}

// This function uses Flood fill / Seed fill algorithm and recursively explores
// the grid in all directions, marking the path (marked) as it progresses 
// through valid cells (not '1' ) on the grid. All reachable cells become 1-s.

void	mark_path(t_frame *game, int row, int col, int **marked)
{
	if (game->map[row][col] != '1' && marked[row][col] != 1)
	{
		marked[row][col] = 1;
		mark_path(game, row, col + 1, marked);
		mark_path(game, row, col - 1, marked);
		mark_path(game, row + 1, col, marked);
		mark_path(game, row - 1, col, marked);
	}
}

// Makes a matrix int **marked, equivalent to char ** games->map,
// calls for mark the path reachable for the Player and then 
// checks if 
void	is_path(t_frame *game)
{
	int	**marked;
	int	i;

	marked = (int **)ft_calloc(game->rows, sizeof(int *));
	i = -1;
	while (++i < game->rows)
		marked[i] = (int *)ft_calloc(game->cols, sizeof(int));
	mark_path(game, game->player[0], game->player[1], marked);
	check_path(game, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
}

// inits 'P'layer's position[cols, rows], number of 'E'xits 
// and 'C'ollactables
void	is_pec(t_frame *game)
{
	int	raw;
	int	col;

	raw = -1;
	while (++raw < game->rows)
	{
		col = -1;
		while (++col < game->cols)
		{
			if (game->map[raw][col] == 'P')
			{
				game->player[0] = raw;
				game->player[1] = col;
			}
			if (game->map[raw][col] == 'E')
				game->exit++;
			if (game->map[raw][col] == 'C')
				game->collectibles++;
		}
	}
}

// inits game->map and!:
//  'P'layer's position[column, row],
//  number of 'E'xits and 'C'ollactables
void	init_frame_map(t_frame *game, int fd)
{
	int		i;
	char	*line;

	game->map = (char **)ft_calloc(game->rows + 1, sizeof(char *));
	if (!game->map)
		error_exit("Error: memory allocation failed\n", fd, NULL, NULL);
	game->map[game->rows] = NULL;
	i = -1;
	while (++i < game->rows)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
		{
			while (--i >= 0)
				free(game->map[i]);
			free(game->map);
			error_exit("Error: memory allocation failed\n", fd, NULL, NULL);
		}
	}
	is_pec(game);
	close(fd);
}
