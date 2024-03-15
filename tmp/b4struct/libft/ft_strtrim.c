/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:24 by oruban            #+#    #+#             */
/*   Updated: 2023/11/28 21:11:26 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strtrim
// Prototype char *ft_strtrim(char const *s1, char const *set);
// Turn in files -
// Parameters #1. The string to be trimmed.
// #2. The reference set of characters to trim.
// Return value The trimmed string. NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

#include "libft.h"

static size_t	trmdstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	start_i;

	start_i = 0;
	i = 0;
	while (i <= ft_strlen(set))
	{
		i++;
		if (set[i - 1] == s1[start_i] && start_i < ft_strlen(s1))
		{
			start_i++;
			i = 0;
		}
	}
	return (start_i);
}

static size_t	trmdfinish(char const *s1, char const *set, size_t start_i)
{
	size_t	i;
	size_t	finish_i;

	finish_i = ft_strlen(s1) - 1;
	i = 0;
	while (i <= ft_strlen(set))
	{
		i++;
		if (set[i - 1] == s1[finish_i] && finish_i > start_i)
		{
			finish_i--;
			i = 0;
		}
	}
	return (finish_i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	finish_i;
	char	*out;

	start_i = trmdstart(s1, set);
	if (start_i < ft_strlen(s1))
	{
		finish_i = trmdfinish(s1, set, start_i);
		out = ft_calloc(1, finish_i - start_i + 1 + 1);
		if (!out)
			return (NULL);
		out[finish_i - start_i + 1] = 0;
	}
	else
	{
		finish_i = start_i;
		out = ft_calloc(1, 1);
		if (!out)
			return (NULL);
		out[0] = 0;
	}
	if (out != NULL)
		out = (char *) ft_memmove(out, s1 + start_i, finish_i - start_i + 1);
	return (out);
}
