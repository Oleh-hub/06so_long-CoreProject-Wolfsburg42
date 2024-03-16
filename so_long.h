/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:53 by oruban            #+#    #+#             */
/*   Updated: 2024/03/16 20:05:09 by oruban           ###   ########.fr       */
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
	int		rows;
	int		cols;
	int		collectibles;
	int		exit;
	int		steps;
	int		collected;
}			t_frame;

/* paramters for the funciton called from ismiddle*/
typedef struct s_func_pars
{
	char	*line;
	char	*next_l;
	int		cols;
	int		fd;
}			t_func_pars;

/* PEC0 counters 2 be given as a parameter to teh function called
 from ismiddle */
typedef struct s_peco
{
	int		p;
	int		e;
	int		c;
	int		o;
	int		l;
}				t_peco;

void	error_exit(const char *s, int fd, char *line, char *line1);
#endif  /* SO_LONG_H */
