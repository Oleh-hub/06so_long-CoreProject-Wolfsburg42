/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:05:46 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 17:53:08 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/memchr
// Defined in header <string.h>		
// void *memchr( const void *ptr, int ch, size_t count );	(1)	
// /*QVoid*/ *memchr( /*QVoid*/ *ptr, int ch, size_t count );	(2)	(since C23)
// 1) Finds the first occurrence of (unsigned char)ch in the initial count 
// bytes (each interpreted as unsigned char) of the object pointed to by ptr.
// 2) Type-generic function equivalent to (1). Let T be an unqualified object 
// type (including void).
// If ptr is of type const T*, the return type is const void*.
// Otherwise, if ptr is of type T*, the return type is void*.
// Otherwise, the behavior is undefined.
// If a macro definition of each of these generic functions is suppressed to 
// access an actual function (e.g. if (memchr) or a function pointer is used), 
// the actual function declaration (1) becomes visible.
// The behavior is undefined if access occurs beyond the end of the array 
// searched. The behavior is undefined if ptr is a null pointer.

// This function behaves as if it reads the bytes sequentially and stops as 
// soon as a matching bytes is found: if the array pointed to by ptr is 
// smaller than count, but the match is found within the array, the behavior 
// is well-defined.

// (since C11)
// Parameters
// ptr	-	pointer to the object to be examined
// ch	-	bytes to search for
// count	-	max number of bytes to examine
// Return value
// Pointer to the location of the byte, or a null pointer if no such byte 
// is found.

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t				i;
	const unsigned char	*p;

	i = 0;
	p = ptr;
	while (i < count && p[i] != (unsigned char) ch)
		i++;
	if (i == count)
		return (NULL);
	return ((unsigned char *) p + i);
}
