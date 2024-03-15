/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:22:38 by oruban            #+#    #+#             */
/*   Updated: 2023/11/14 19:31:43 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/strdup
// Defined in header <string.h>		
// char *strdup( const char *src );		(since C23)
// Returns a pointer to a null-terminated byte string, which is a duplicate of 
// the string pointed to by src. The space for the new string is obtained as if 
// the malloc was invoked. The returned pointer must be passed to free to avoid 
// a memory leak.
// If an error occurs, a null pointer is returned and errno might be set.
// Parameters
// src	-	pointer to the null-terminated byte string to duplicate
// Return value
// A pointer to the newly allocated string, or a null pointer if an error 
// occurred.
// Notes
// The function is identical to the POSIX strdup.

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (dup != NULL)
	{
		i = 0;
		while (i < len)
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}
