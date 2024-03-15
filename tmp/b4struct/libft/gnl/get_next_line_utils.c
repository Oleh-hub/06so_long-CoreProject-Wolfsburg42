/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:25:53 by oruban            #+#    #+#             */
/*   Updated: 2024/01/02 10:07:34 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// SYNOPSIS
// 	   #include <string.h>
// 	   size_t strlen(const char *s);
// DESCRIPTION
// 	   The strlen() function calculates the length of the string pointed 
// 	   to by s, excluding the terminating null byte ('\0').
// RETURN VALUE
// 	   The strlen() function returns the number of bytes in the string pointed 
// to by s.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

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

// https://devdocs.io/c/string/byte/strchr  :
// Defined in header <string.h>		
// char *strchr( const char *str, int ch );
// Finds the first occurrence of ch (after conversion to char as if by (char)ch)
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

// char	*ft_strchr(const char *str, int ch)
// {
// 	size_t	i;
// 	size_t	str_len;

// 	str_len = ft_strlen(str);
// 	i = 0;
// 	while (i <= str_len)
// 	{
// 		if ((unsigned char) ch == (unsigned char) str[i])
// 			return ((char *) str + i);
// 		++i;
// 	}
// 	if ((unsigned char) ch == (unsigned char) str[i])
// 		return ((char *) str + i);
// 	return (NULL);
// }
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}

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

// !!!modified during GNL to avoid timeouts 240103 - roi
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = malloc(len_s1 + len_s2 + 1);
	if (!out)
		return (out);
	i = 0;
	while (i < len_s1)
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		out[i++] = s2[j++];
	out[i] = 0;
	return (out);
}
