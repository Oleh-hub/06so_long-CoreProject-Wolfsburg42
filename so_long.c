/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/18 20:05:49 by oruban           ###   ########.fr       */
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

static void	is_path(t_frame *game)
{
	(void) game;
	int	**marked;
	int	i;

	marked = (int **)ft_calloc(game->rows, sizeof(int *));
	i = -1;
	while (++i < game->rows)
		marked[i] = (int *)ft_calloc(game->cols, sizeof(int));
	{	// tracing
		ft_printf("b4 mark_path(), marked:\n");
		for (int i = 0; i < game->rows; i++)
			{
				for (int j = 0; j < game->cols; j++)
					ft_printf("%i", marked[i][j]);
				ft_printf("\n");
			}
		ft_printf(" b4 mark_path(), game->map:\n");
		for (int i = 0; i < game->rows; i++)
			ft_printf("%s\n", game->map[i]);
	}
	// mark_path();
	// check_path();
	while(--i >= 0)
		free(marked[i]);
	free(marked);
}

// inits 'P'layer's position[cols, rows], number of 'E'xits 
// and 'C'ollactables
static void is_pec(t_frame *game)
{
	(void) game;
}


// inits game->map, 'P'layer's position[cols, rows], number of 'E'xits 
// and 'C'ollactables
static void init_frame_map(t_frame *game, int fd)
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

/* checks the map.name and calls for map_valid that checks the map content */
static t_frame	*map_check(char *av)
{
	t_frame	*game;
	char	*ext;
	int		fd;
	int		i;

	ext = ft_strrchr(av, '.');
	if (!ext || ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
		error_exit("Error: map name should be '*.ber' format\n", 0, NULL, NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_exit("Error: map file cannot be open\n", 0, NULL, NULL);
	game = (t_frame *)ft_calloc(1, sizeof(t_frame));
	if (!game)
		error_exit("Error: Memory allocation failed\n", fd, NULL, NULL);
	init_frame_start(game);
	if (!map_valid(fd, game))
		ft_printf("map %s is not valid :)\n", av);
	// ft_printf("The map %s int is valid full ini of t_frame *game and check of path to b follwed\n", av); //
	fd = open(av, O_RDONLY);
	init_frame_map(game, fd);
	ft_printf("The map %s is included into t_frame *game.  The path to b follwed\n", av); //
	is_path(game);
	ft_printf("The path to b finished here\n"); //
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
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
