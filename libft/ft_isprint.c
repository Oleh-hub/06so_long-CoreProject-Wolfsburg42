/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:03:40 by oruban            #+#    #+#             */
/*   Updated: 2023/11/14 19:14:50 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// isprint()
// checks for any printable character including space.
// RETURN VALUE
// The values returned are nonzero if the character c falls into the tested 
// class, and zero if not.

// return(c >= 32 && c <= 126) ? 1 : 0;

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
