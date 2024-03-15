/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:04:53 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 18:04:53 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
// 	   #include <string.h>
// 	   size_t strlen(const char *s);
// DESCRIPTION
// 	   The strlen() function calculates the length of the string pointed 
// 	   to by s, excluding the terminating null byte ('\0').
// RETURN VALUE
// 	   The strlen() function returns the number of bytes in the string pointed 
// to by s.

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
