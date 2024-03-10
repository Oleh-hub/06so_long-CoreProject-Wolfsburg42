/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:41 by oruban            #+#    #+#             */
/*   Updated: 2023/11/28 21:07:40 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_split
// Prototype char **ft_split(char const *s, char c);
// Parameters #1. The string to be split.
// #2. The delimiter character.
// Return value The array of new strings resulting from the split.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must be
// ended by a NULL pointer.

// not more then 5 functions are allowed in 1 file by norminette.

#include "libft.h"

// counts words - the characters between separators
static size_t	words_count(char const *s, char c)
{
	size_t	counter;
	int		in_word_flag;

	counter = 0;
	in_word_flag = 0;
	while (*s)
	{
		if (*s == c)
			in_word_flag = 0;
		if (*s != c && 0 == in_word_flag)
		{
			counter++;
			in_word_flag = 1;
		}
		s++;
	}
	return (counter);
}

static void	ft_free(char **carray)
{
	int	i;

	i = -1;
	while (carray[++i] != NULL)
		free(carray[i]);
	free(carray);
}

static char	**words2carray(char **carray, const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*start;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			start = (char *)s;
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			carray[i] = ft_substr(start, 0, len);
			if (!carray[i])
				return (ft_free(carray), NULL);
			++i;
		}
		if (*s)
			s++;
	}
	return (carray);
}

char	**ft_split(char const *s, char c)
{
	char	**carray;
	size_t	carray_size;

	if (!s)
		return (NULL);
	carray_size = words_count(s, c);
	carray = ft_calloc((carray_size + 1), sizeof(char *));
	if (NULL == carray)
		return (NULL);
	carray[carray_size] = NULL;
	carray = words2carray(carray, s, c);
	return (carray);
}
