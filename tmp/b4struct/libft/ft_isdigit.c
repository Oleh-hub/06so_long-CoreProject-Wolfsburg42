/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:17:55 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 16:17:55 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isdigit()  #include <ctype.h>
// checks for a digit (0 through 9).
// RETURN VALUE The values returned are nonzero if the character c falls 
// into the tested class, and zero if not.

// return ((c >= '0' && c <= '9') ? 1 : 0);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
