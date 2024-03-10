/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:07:55 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 17:54:36 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://devdocs.io/c/string/byte/memcmp
// Defined in header <string.h>		
// int memcmp( const void* lhs, const void* rhs, size_t count );		
// Compares the first count bytes of the objects pointed to by lhs and rhs. The
//  comparison is done lexicographically.

// The sign of the result is the sign of the difference between the values of 
// the first pair of bytes (both interpreted as unsigned char) that differ in 
// the objects being compared.

// The behavior is undefined if access occurs beyond the end of either object 
// pointed to by lhs and rhs. The behavior is undefined if either lhs or rhs 
// is a null pointer.

// Parameters
// lhs, rhs	-	pointers to the objects to compare
// count	-	number of bytes to examine
// Return value
// Negative value if lhs appears before rhs in lexicographical order.
// Zero if lhs and rhs compare equal, or if count is zero.
// Positive value if lhs appears after rhs in lexicographical order.

// Notes
// This function reads object representations, not the object values, and is
//  typically meaningful for byte arrays only: structs may have padding bytes 
//  whose values are indeterminate, the values of any bytes beyond the last 
//  stored member in a union are indeterminate, and a type may have two or 
//  more representations for the same value (different encodings for +0 and 
//  -0 or for +0.0 and –0.0, indeterminate padding bits within the type).

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	const unsigned char	*l;
	const unsigned char	*r;
	size_t				i;

	l = lhs;
	r = rhs;
	i = 0;
	while (i < count && l[i] == r[i])
		i++;
	if (i == count)
		return (0);
	return (l[i] - r[i]);
}
