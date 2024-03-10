/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upxx_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:37:40 by oruban            #+#    #+#             */
/*   Updated: 2024/02/27 18:42:48 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints out unsigned integer 
// PARAMETERS
// 'unsigned int u 'to print out and 'int reset_counter' that should always 
// be = 1 (it is = 0 only in recursion calls insiged the funciton)
// RETURN
// the number of outputed symbols or -1 if a write fails
// NB:
// it is not polite to create a variable that can be negative for a counter
// but i want to use it later in ft_itoa, besides
// the counter i is of int type because i is never > (UINT_MAX = 4294967295)
int	uns_out(unsigned int u, int reset_counter)
{
	char		c;
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 9)
		uns_out(u / 10, 0);
	c = u % 10 + '0';
	if (-1 == write(1, &c, 1))
		return (-1);
	return (++i);
}

// prints out a unsingned int number into hexedecimal format on eof '%xXp'
// PARAMETERS
// 'unsingned int u' - the number to be converted
// 'char x' can be 'x', 'X' or 'p' to output %x, %X or %p
// 'int reset_counter' = 1 for every call exeept recursion inside the function
// RETURN
// the nuber of outputed characters
unsigned int	xxc_out(unsigned int u, int reset_counter, char x)
{
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 15)
		xxc_out(u / 16, 0, x);
	if ('x' == x)
		if (-1 == write(1, &HEX[u % 16], 1))
			return (-1);
	if ('X' == x)
		if (-1 == write(1, &HEXCAP[u % 16], 1))
			return (-1);
	return (++i);
}

// prints out a unsingned long number into hexedecimal format of a 
// pointer address'%p'
// PARAMETERS
// 'unsingned long u' - the number to be converted
// 'char x' can be 'x', 'X' or 'p' to output %x, %X or %p
// 'int reset_counter' = 1 for every call exeept recursion inside the function
// RETURN
// the nuber of outputed characters
unsigned int	p_out(unsigned long u, int reset_counter, char x)
{
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 15)
		p_out(u / 16, 0, x);
	if (-1 == write(1, &HEX[u % 16], 1))
		return (-1);
	return (++i);
}

unsigned int	hex_out(char x, va_list ap)
{
	unsigned int	i;
	unsigned long	ul;
	unsigned int	ui;

	i = 0;
	if ('p' == x)
	{
		ul = va_arg(ap, unsigned long);
		i = write(1, "0x", 2);
		if ((int) i < 0)
			return (i);
		i += p_out(ul, 1, x);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		if ('x' == x)
			i = xxc_out(ui, 1, x);
		else if ('X' == x)
			i = xxc_out(ui, 1, x);
	}
	return (i);
}
