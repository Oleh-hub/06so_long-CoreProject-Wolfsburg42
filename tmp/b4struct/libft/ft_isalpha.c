/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:15:11 by oruban            #+#    #+#             */
/*   Updated: 2023/11/13 16:15:11 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// isalpha()
// checks for an alphabetic character; in the standard "C" locale, it is 
// equivalent to (isupper(c) || islower(c)).   In  some  locales, there may be 
// additional characters for which isalpha() is true—letters which are neither 
// uppercase nor lowercase.
// RETURN VALUE The values returned are nonzero if the character c falls 
// into the tested class, and zero if not.

// return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0;

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
