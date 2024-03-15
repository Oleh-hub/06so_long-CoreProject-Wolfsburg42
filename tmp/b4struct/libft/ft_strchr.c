/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:20:13 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 18:03:35 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/strchr
// NAME
//        strchr, strrchr, strchrnul - locate character in string
// SYNOPSIS
//        #include <string.h>
//		  char *strchr( const char *str, int ch );
// 		str	-	pointer to the null-terminated byte string to be analyzed
// 		ch	-	character to search for
// DESCRIPTION
// 		Finds the first occurrence of ch (after conversion to char as if by 
// 		(char)ch) in the null-terminated byte string pointed to by str (each 
// 		character interpreted as unsigned char). The terminating null 
// 		character is considered to be a part of the string and can be found 
// 		when searching for '\0'.
// RETURN VALUE
// 	Pointer to the found character in str, or null pointer if no such 
// 	character is found.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s) && (unsigned char) s[i] != (unsigned char) c)
		i++;
	if ((unsigned char) c != '\0' && ft_strlen(s) == i - 1)
		return (NULL);
	return ((char *) s + i);
}
