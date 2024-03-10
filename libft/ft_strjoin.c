/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:37 by oruban            #+#    #+#             */
/*   Updated: 2023/11/15 15:29:07 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strjoin
// Prototype char *ft_strjoin(char const *s1, char const *s2);
// Turn in files -
// Parameters #1. The prefix string.
// #2. The suffix string.
// Return value The new string. NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (out != NULL)
	{
		i = 0;
		while (i < ft_strlen(s1))
		{
			out[i] = s1[i];
			i++;
		}
		j = 0;
		while (j < ft_strlen(s2))
		{
			out[i] = s2[j];
			i++;
			j++;
		}
		out[i] = '\0';
	}
	return (out);
}
