/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:23 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 17:17:23 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//		#include <string.h>
//		void *memset(void *s, int c, size_t n);
// DESCRIPTION
//		The memset() function fills the first n bytes of the memory area
//		pointed to by s with the constant byte c.
// RETURN VALUE
//		The memset() function returns a pointer to the memory area s.

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pntr;
	size_t			i;

	pntr = s;
	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		pntr[i] = c;
		i++;
	}
	return (s);
}
