/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:05:06 by oruban            #+#    #+#             */
/*   Updated: 2023/11/28 21:14:09 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_itoa
// Prototype char *ft_itoa(int n);
// Turn in files -
// Parameters #1. the integer to convert.
// Return value The string representing the integer. NULL if the
// allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

// out = ft_memset(out, 'H', nsize); ""is nessessery to initialise the 
// string out - roi

#include "libft.h"
#include <limits.h>

static char	*i2a(int n, char *out)
{
	int	i;

	if (0 == n)
		out[0] = '0';
	else
	{
		i = ft_strlen(out);
		while (i > 0)
		{
			out[--i] = n % 10 + '0';
			n = n / 10;
		}
		if ('0' == out[0])
			out[0] = '-';
	}
	return (out);
}

static int	numlen(int n)
{
	if (n > 0)
		return (1 + numlen(n / 10));
	else
		return (0);
}
// 	// nsize = minus > 0 ? numlen(n) : numlen(n) + 1;
// out = malloc((nsize + 1) * sizeof(c

static int	find_size(int n)
{
	int		nsize;

	if (n < 0)
		nsize = numlen(-n) + 1;
	else
	{
		if (!n)
			nsize = 1;
		else
			nsize = numlen(n);
	}
	return (nsize);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		nsize;

	if (-2147483648 == n)
	{
		out = malloc(sizeof("-2147483648"));
		if (!out)
			return (NULL);
		out[ft_strlen("-2147483648")] = '\0';
		return (ft_memmove(out, "-2147483648", 11));
	}
	nsize = find_size (n);
	if (n < 0)
		n = -n;
	out = malloc((nsize + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out = ft_memset(out, 'H', nsize);
	out[nsize] = '\0';
	out = i2a(n, out);
	return (out);
}
