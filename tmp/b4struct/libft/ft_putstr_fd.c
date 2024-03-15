/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:17 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 18:00:11 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putstr_fd
// Prototype void ft_putstr_fd(char *s, int fd);
// Turn in files -
// Parameters #1. The string to output.
// #2. The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the string ’s’ to the given file
// descriptor.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
