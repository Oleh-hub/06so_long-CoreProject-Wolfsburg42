/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:30 by oruban            #+#    #+#             */
/*   Updated: 2023/11/26 12:53:51 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_substr
// Prototype char *ft_substr(char const *s, unsigned int start,
// size_t len);
// Parameters #1. The string from which to create the substring.
// #2. The start index of the substring in the string
// ’s’.
// #3. The maximum length of the substring.
// Return value The substring. NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

// Thx Richard. "Tell me whyyyyyy..." : 
// if ((size_t)start >= ft_strlen(s))
// 	return (ft_strdup(""));

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = s[start + i];
	out[i] = '\0';
	return (out);
}
