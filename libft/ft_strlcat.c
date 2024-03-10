/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:27:19 by oruban            #+#    #+#             */
/*   Updated: 2023/11/26 06:55:09 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FreeBSD Manual Pages
// https://man.freebsd.org/cgi/man.cgi?query=strlcat&sektion=3
// NAME
//        strlcpy,	strlcat	-- size-bounded	string copying and concatenation
// LIBRARY
//        Standard	C Library (libc, -lc)
// SYNOPSIS
//        #include	<string.h>
//  size_t 
// 	strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
//  size_t
//  strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
// DESCRIPTION
// The strlcpy() and strlcat() functions copy and concatenate strings with
// the  same  input	parameters and output result as	snprintf(3).  They are
// designed	to be safer, more consistent, and less	error  prone  replace-
// ments for the easily misused functions strncpy(3) and strncat(3).

// strlcpy()  and  strlcat()  take the full	size of	the destination	buffer
// and guarantee NUL-termination if	there is room.	Note that room for the
// NUL should be included in dstsize.

// strlcpy() copies	up to dstsize -	1 characters from the  string  src  to
// dst, NUL-terminating the	result if dstsize is not 0.

// strlcat() appends string	src to the end of dst.	It will	append at most
// dstsize	- strlen(dst) -	1 characters.  It will then NUL-terminate, un-
// less dstsize is 0 or the	original dst string was	 longer	 than  dstsize
// (in  practice this should not happen as it means	that either dstsize is
// incorrect or that dst is	not a proper string).

// If the src and dst strings overlap, the behavior	is undefined.

// RETURN VALUES
// Besides quibbles	over the return	type (size_t versus  int)  and	signal
// handler	safety (snprintf(3) is not entirely safe on some systems), the
// following two are equivalent:
//   n = strlcpy(dst, src, len);
//   n = snprintf(dst, len, "%s", src);
// Like snprintf(3), the strlcpy() and strlcat() functions return the  to-
// tal  length  of	the  string  they tried	to create.  For	strlcpy() that
// means the length	of src.	 For strlcat() that means the  initial	length
// of dst plus the length of src.
// If  the	return	value  is >= dstsize, the output string	has been trun-
// cated.  It is the caller's responsibility to handle this.

// SYNOPSIS 20.11.2023
// size_t strlcat(char *dst, const char *src, size_t dstsize);
// DESCRIPTION
// strlcat() appends string src to the end of dst.  It will append at most
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
// dstsize is 0 or the original dst string was longer than dstsize (in prac-
// tice this should not happen as it means that either dstsize is incorrect
// or that dst is not a proper string).
// Почему return (destsize + ft_strlen(src)); все еще не ясно. Ричард у кот
// я это передрал то же не знает

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	i;
	size_t	j;

	destlen = ft_strlen(dst);
	i = destlen;
	j = 0;
	if (destsize == 0 || destlen > destsize)
		return (destsize + ft_strlen(src));
	while (i < destsize - 1 && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (destlen + ft_strlen(src));
}
