/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:15 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 18:24:29 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/strrchr :
// Defined in header <string.h>		
// char *strrchr( const char *str, int ch );

// Finds the last occurrence of ch (after conversion to char as if by (char)ch)
// in the null-terminated byte string pointed to by str (each character 
// interpreted as unsigned char). The terminating null character is considered 
// to be a part of the string and can be found if searching for '\0'.

// Parameters
// str	-	pointer to the null-terminated byte string to be analyzed
// ch	-	character to search for
// Return value
// Pointer to the found character in str, or null pointer if no such character 
// is found.

// roi:
// in the funciton ch is been converted into (unsigned char) instead of (char) 
// otherwise ft_strrchr does not handle symbols from extanded ASCII table the 
// was strrchr does 

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if ((unsigned char) ch == (unsigned char) str[i])
			return ((char *) str + i);
		i--;
	}
	if ((unsigned char) ch == (unsigned char) str[i])
		return ((char *) str + i);
	return (NULL);
}
