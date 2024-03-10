/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:09 by oruban            #+#    #+#             */
/*   Updated: 2023/11/29 14:53:49 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NAME
// 	   memmove - copy memory area
// SYNOPSIS
// 	   #include <string.h>
// 	   void *memmove(void *dest, const void *src, size_t n);
// DESCRIPTION
// 	   The  memmove() function copies n bytes from memory area src to memory 
// 		area dest.  The memory areas may overlap: copying takes place as
// 	   though the bytes in src are first copied into a temporary array that
// 		 does not overlap src or dest, and the bytes are then copied  from
// 	   the temporary array to dest.
// RETURN VALUE
// 	   The memmove() function returns a pointer to dest.

// Implementation: 
// roi: Memory efficient code. Checking first if the arraies are overlapping. 
// If so copying to dest via a src-copy array if not direct copying from src.

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	if (dest < src && n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (dest > src && n)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
