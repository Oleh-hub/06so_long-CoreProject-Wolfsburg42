/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:16:32 by oruban            #+#    #+#             */
/*   Updated: 2023/11/26 07:17:14 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
// 	   #include <string.h>
// 	   void *memcpy(void *dest, const void *src, size_t n);
// DESCRIPTION
// 	   The  memcpy() function copies n bytes from memory area src to memory 
// area dest. 
// 	   The memory areas must not overlap. Use memmove(3) if the memory areas 
// do overlap.
// RETURN VALUE
// 	   The memcpy() function returns a pointer to dest.

// if (dest == src) return (dest); - in case of overlapping

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_pnt;
	const unsigned char	*src_pnt;

	i = 0;
	dest_pnt = dest;
	src_pnt = src;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		dest_pnt[i] = src_pnt[i];
		i++;
	}
	return (dest);
}
