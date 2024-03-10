/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:06:42 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 18:07:22 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strmapi
// Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));
// Turn in files -
// Parameters #1. The string on which to iterate.
// #2. The function to apply to each character.
// Return value The string created from the successive applications
// of ’f’. Returns NULL if the allocation fails.
// External functs. malloc
// Description Applies the function ’f’ to each character of the
// string ’s’ to create a new string (with malloc(3))
// resulting from successive applications of ’f’.

// more presize task formulation:
// https://github.com/Oksanatishka/42_libft/blob/master/ft_strmapi.c
/* 2018/08/22
** Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s and its index.
** Return value The “fresh” string created from the successive applications of
** f.
** Libc functions malloc(3)
*/
// JUNE 30, 2023
// https://42.nauman.cc/2023/06/30/part-ii-ft-strmapi/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	if (NULL == s || NULL == f)
		return (NULL);
	out = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (NULL == out)
		return (NULL);
	out[ft_strlen(s)] = '\0';
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
