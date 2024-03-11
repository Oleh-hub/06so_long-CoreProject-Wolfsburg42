/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:53 by oruban            #+#    #+#             */
/*   Updated: 2024/03/11 09:27:51 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # include <mlx.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>                     // open()

typedef struct s_frame
{
	int		rows;
	int		cols;
	int		herbs;
	int		gate;
	int		steps;
	int		collected;
}			t_frame;
#endif  /* SO_LONG_H */