/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:09 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 17:18:12 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putchar_fd
// Prototype void ft_putchar_fd(char c, int fd);
// Turn in files -
// Parameters #1. The character to output.
// #2. The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the character ’c’ to the given file
// descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (-1 == write(fd, &c, 1))
		write(1, "An error has occured during writing into the file.\n", 51);
}
