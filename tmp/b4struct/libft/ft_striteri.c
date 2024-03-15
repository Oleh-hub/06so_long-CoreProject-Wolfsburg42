/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:23:53 by oruban            #+#    #+#             */
/*   Updated: 2023/11/22 18:14:36 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_striteri
// Prototype void ft_striteri(char *s, void (*f)(unsigned int, char*));
// Turn in files -
// Parameters #1. The string on which to iterate.
// #2. The function to apply to each character.
// Return value None.
// External functs. None
// Description Applies the function f to each character of the
// string passed as argument, and passing its index
// as first argument. Each character is passed by
// address to f to be modified if necessary
// "Tell me why!" : f(i, &s[i]);

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
