/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:06:08 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 17:46:55 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
// 	   #include <strings.h>
// 	   void bzero(void *s, size_t n);
// DESCRIPTION
// 	   The  bzero()  function  erases the data in the n bytes of the memory 
// 	   starting at the location pointed to by s, by writing zeros (bytes
// 	   containing '\0') to that area.
// RETURN VALUE
// 	   None.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pntr;
	size_t			i;

	pntr = s;
	i = 0;
	while (i < n)
	{
		pntr[i] = '\0';
		i++;
	}
}
