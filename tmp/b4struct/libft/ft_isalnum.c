/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:13:47 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 16:13:47 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalnum()  #include <ctype.h>
// checks for an alphanumeric character; it is equivalent to (isalpha(c) || 
// isdigit(c)).
// RETURN VALUE The values returned are nonzero if the character c falls into 
// the tested class, and zero if not.

// return (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
// (c >= '0' && c <= '9')) ? 1 : 0);

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
