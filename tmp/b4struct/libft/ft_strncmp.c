/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:07:32 by oruban            #+#    #+#             */
/*   Updated: 2023/11/26 09:04:03 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/strncmp :
// Defined in header <string.h>		
// int strncmp( const char* lhs, const char* rhs, size_t count );		
// Compares at most count characters of two possibly null-terminated arrays. 
// The comparison is done lexicographically. Characters following the null 
// character are not compared.
// The sign of the result is the sign of the difference between the values of 
// the first pair of characters (both interpreted as unsigned char) that 
// differ in the arrays being compared.
// The behavior is undefined when access occurs past the end of either array lhs
// or rhs. The behavior is undefined when either lhs or rhs is the null pointer.
// Parameters
// lhs, rhs	-	pointers to the possibly null-terminated arrays to compare
// count	-	maximum number of characters to compare
// Return value
// Negative value if lhs appears before rhs in lexicographical order.
// Zero if lhs and rhs compare equal, or if count is zero.
// Positive value if lhs appears after rhs in lexicographical order.

// 	if (0 == count) return (0); is nessesary according to francinette

#include "libft.h"

int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t	i;

	if (0 == count)
		return (0);
	i = 0;
	while (i < count - 1 && lhs[i] == rhs[i] && lhs[i])
		i++;
	return ((unsigned char) lhs[i] - (unsigned char) rhs[i]);
}
