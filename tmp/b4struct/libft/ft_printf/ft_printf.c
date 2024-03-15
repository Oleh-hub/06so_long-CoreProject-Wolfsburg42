/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:36:22 by oruban            #+#    #+#             */
/*   Updated: 2024/01/22 10:41:52 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stdarg.h included just as a reminder. it is included in ft_printf.h as well
// #include <stdarg.h>
#include "ft_printf.h"

static int	int_out(int count, va_list ap)
{
	int		int_out;
	char	*str_out;

	int_out = va_arg(ap, int);
	str_out = ft_itoa(int_out);
	count += write(1, str_out, ft_strlen(str_out));
	free(str_out);
	return (count);
}

static int	str_out(int count, va_list ap)
{
	char	*str_out;

	str_out = NULL;
	str_out = va_arg(ap, char *);
	if (!str_out)
		return (count += write(1, "(null)", 6));
	count += write(1, str_out, ft_strlen(str_out));
	return (count);
}

static int	char_out(int count, va_list ap)
{
	char	char_out;

	char_out = (char) va_arg(ap, int);
	count += write(1, &char_out, 1);
	return (count);
}

static int	cnvrtns_chc(const char**s, int count, va_list ap)
{
	unsigned int	uns;

	if ('%' == **s)
		count += write(1, *s, 1);
	else if ('c' == **s)
		count = char_out(count, ap);
	else if ('s' == **s)
		count = str_out(count, ap);
	else if ('d' == **s || 'i' == **s)
		count = int_out(count, ap);
	else if ('u' == **s)
	{
		uns = va_arg(ap, unsigned int);
		count += (unsigned int) uns_out(uns, 1);
	}
	else if ('x' == **s || 'X' == **s || 'p' == **s)
		count += (unsigned int) hex_out(**s, ap);
	(*s)++;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	count;
	va_list			ap;

	count = 0;
	if (!*s || !s)
		return (0);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *++s)
			count = cnvrtns_chc(&s, count, ap);
		if (*s && *s != '%')
		{
			count += write(1, s, 1);
			s++;
		}
	}
	va_end(ap);
	return (count);
}
