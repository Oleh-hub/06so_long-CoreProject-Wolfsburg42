/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:03 by oruban            #+#    #+#             */
/*   Updated: 2023/11/14 19:34:38 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putnbr_fd
// Prototype void ft_putnbr_fd(int n, int fd);
// Turn in files -
// Parameters #1. The integer to output.
// #2. The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the integer ’n’ to the given file
// descriptor.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (-2147483648 == n)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	c = (n + '0');
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10 + '0');
	}
	write(fd, &c, 1);
}
