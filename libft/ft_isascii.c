/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:16:33 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 16:16:33 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// isascii()
// checks whether c is a 7-bit unsigned char value that fits into the ASCII 
// character set.
// RETURN VALUE The values returned are nonzero if the character c falls 
// into the tested class, and zero if not.

// return ((c >= 0 && c <= 127) ? 1 : 0);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
