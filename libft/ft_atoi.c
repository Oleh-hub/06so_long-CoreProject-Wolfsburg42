/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:43:14 by oruban            #+#    #+#             */
/*   Updated: 2023/11/24 18:20:17 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Defined in header <stdlib.h>		
// int       atoi( const char *str );		
// Interprets an integer value in a byte string pointed to by str. The implied 
// radix is always 10.
// Discards any whitespace characters until the first non-whitespace character 
// is found, then takes as many characters as possible to form a valid integer 
// number representation and converts them to an integer value. The valid 
// integer value consists of the following parts:
// (optional) plus or minus sign
// numeric digits
// If the value of the result cannot be represented, i.e. the converted value 
// falls out of range of the corresponding return type, the behavior is 
// undefined.
// Parameters
// str	-	pointer to the null-terminated byte string to be interpreted
// Return value
// Integer value corresponding to the contents of str on success.
// If no conversion can be performed, 0 is returned.

// Notes
// The name stands for "ASCII to integer".
// piscine
// • The string can start with an arbitray amount of white space 
// (as determined by isspace(3))
// isspace()
// DESCRIPTION
// The isspace() function tests for the white-space characters.  For any
// locale, this includes the following standard characters:
// ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''// 

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i])
	{
		while ('\t' == str[i] || '\n' == str[i] || '\v' == str[i]
			|| '\f' == str[i] || '\r' == str[i] || ' ' == str[i])
			i++;
		if ('+' == str[i] || '-' == str[i])
		{
			if ('-' == str[i])
				sign = -sign;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = 10 * num + str[i] - '0';
			i++;
		}
	}
	return (sign * num);
}
