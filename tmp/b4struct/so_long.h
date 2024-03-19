/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:53 by oruban            #+#    #+#             */
/*   Updated: 2024/03/19 11:04:01 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>                     // open()
// # include <stdbool.h>

typedef struct s_frame
{
	char	**map;
	int		player[2];					// player's coordinated [row][collumn]
	int		rows;						// map rows number
	int		cols;						// map columns number
	int		collectibles;				// collectibles number
	int		exit;						// exit number
	int		steps;
	int		collected;
}			t_frame;

void	error_exit(const char *s, int fd, char *line, char *line1);
#endif  /* SO_LONG_H */
