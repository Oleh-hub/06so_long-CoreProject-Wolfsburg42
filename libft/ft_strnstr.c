/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:10:16 by oruban            #+#    #+#             */
/*   Updated: 2023/11/22 18:38:42 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NAME
//      strnstr — locate a substring in a string
// LIBRARY
//      Utility functions from BSD systems (libbsd, -lbsd)
// SYNOPSIS
//      #include <string.h>
//      (See libbsd(7) for include usage.)
//      char *strnstr(const char *big, const char *little, size_t len);
// DESCRIPTION
// The strnstr() function locates the first occurrence of the null-terminated 
// string little in the string big, where not more than len characters are 
// searched. 
// Characters that appear after a ‘\0’ character are not searched.  Since the 
// strnstr() function is a FreeBSD specific API, it should only be used when
// portability is not a concern.
// RETURN VALUES
//  If little is an empty string, big is returned; if little occurs nowhere 
//  in big, NULL is returned; otherwise a pointer to the first character of 
//  the first occurrence of little is returned.

// DESCRIPTION 21.11.2023
// The strnstr() function locates the first occurrence of the null-termi-
// nated string needle in the string haystack, where not more than len char-
// acters are searched.  Characters that appear after a `\0' character are
// not searched.
// RETURN VALUES
// If needle is an empty string, haystack is returned; if needle occurs
// nowhere in haystack, NULL is returned; otherwise a pointer to the first
// character of the first occurrence of needle is returned.

#include "libft.h"

// #include <stdio.h>
// #include <string.h>
// char	*ft_strnstr(const char *big, const char *little, size_t len);

// int main()
// {
//         // perfecly done:
// 		// char *s1 = "MZIRIBMZIRIBMZE123";
//         // char *s2 = "";

//         // case is not threated by strnstr: Segmentation fault: 11
// 		// char *s1 = "MZIRIBMZIRIBMZE123";
//         // char *s2 = NULL;
//         // size_t max = 1;

//         // case is not threated by strnstr: Segmentation fault: 11
// 		// char *s1 = NULL;
//         // char *s2 = "MZIRIBMZE";
//        	// size_t max = strlen(s2);

// 		// if len < strlen(needle)
// 		// char *s1 = "MZIRIBMZIRIBMZE123";
//         // char *s2 = "MZIRIBMZE";
//         // size_t max = strlen(s2) - 5;

// 		// char *s1 = "MZIRIBMZIRIBMZE123";
//         // char *s2 = "MZIRIBMZI";
//         // size_t max = strlen(s2);

// 		// TO TEST LAST
// 		// char *s1 = "MZIRIBMZIRIBMZE123";
//         // char *s2 = "MZIRIBMZE";
//         // size_t max = strlen(s2);

// 		char *s1 = "lorem ipsum dolor sit amet";
//         char *s2 = "lorem";
//         size_t max = 15;

// 		printf("main: \n");
// 		char *i1 = strnstr(s1, s2, max);
//         char *i2 = ft_strnstr(s1, s2, max);

// 		printf("'%s' =    strnstr ('%s','%s', %lu) \n", i1, s1, s2, max);
// 		printf("'%s' = ft_strnstr ('%s','%s', %lu) \n", i2, s1, s2, max);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;

	haystack_len = ft_strlen(haystack);
	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > haystack_len || len < ft_strlen(needle))
		return (NULL);
	while (*haystack && len >= ft_strlen(needle))
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
