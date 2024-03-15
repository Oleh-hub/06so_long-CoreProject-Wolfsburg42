/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:17:03 by oruban            #+#    #+#             */
/*   Updated: 2024/01/22 10:55:02 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
// # include "libft/libft.h"
# include "../libft.h"
# define HEX    "0123456789abcdef"
# define HEXCAP "0123456789ABCDEF"

int				ft_printf(const char *s, ...);
int				uns_out(unsigned int u, int i);
unsigned int	hex_out(char x, va_list ap);
#endif
