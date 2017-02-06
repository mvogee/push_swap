/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:47:36 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/06 11:47:37 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_char_len
** 1. if char can be encoded in 1 uft-8 byte char will be less than 128 1 << 7
** 2. if char can be encoded in 2 uft-8 bytes char will be less than 1<<11
** 3. if char can be encoded in 3 utf-8 bytes char will be less than 1<<16
** 4. if char can be encoded in 4 utf-8 bytes char will be less than 1<<21
** finds the smallest ammount of bytes the character can be encoded into.
** RETURN: number of bytes the character can be encoded into.
*/

static int		get_char_len(wchar_t c)
{
	int				bytes;

	bytes = 0;
	if (c < (1 << 7))
		bytes = (1 < MB_CUR_MAX ? 1 : MB_CUR_MAX);
	else if (c < (1 << 11))
		bytes = (2 < MB_CUR_MAX ? 2 : MB_CUR_MAX);
	else if (c < (1 << 16))
		bytes = (3 < MB_CUR_MAX ? 3 : MB_CUR_MAX);
	else if (c < (1 << 21))
		bytes = (4 < MB_CUR_MAX ? 4 : MB_CUR_MAX);
	return (bytes);
}

/*
** char_conversion
** takes a pointer to allocated memory space b
** takes character to be converted
** takes len (how many bytes will be used to encode the character into)
**
** 1. for the first byte we look at the furthest
** 8 bits and turn those into utf-8 standard
** with leading ones for how many bytes are used to encode;
** ex. (500>>6)|0xc0 = [1100 0111]
** 2. following bytes are shifted if needed untill the last byte
** 0x3F is [0011 1111] so (c & 0x3f) gives us two leading 0s in the byte
** 0x80 is [1000 0000] so that will give us a final
** byte that looks like [10xx xxxx]
** 3. the final byte is set to NULL terminater
** no return is needed because we are changing allocated memory space b.
*/

static void		char_conversion(unsigned char *b, wchar_t c, int len)
{
	if (len == 1)
		*b++ = (unsigned char)c;
	else if (len == 2)
	{
		*b++ = (unsigned char)((c >> 6) | 0xc0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		*b++ = (unsigned char)((c >> 12) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		*b++ = (unsigned char)((c >> 18) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
}

/*
** ft_uni_utf8_char
** takes a widechar (wchar_t) and returns the utf-8 bytestring equivilent
** gets the lenght of the how many bytes it will take to encode the character
** allocates sufficient memmory for the character
** does the conversion
** returns char *
*/

char			*ft_uni_utf8_char(wchar_t c)
{
	int				charlen;
	unsigned char	*retptr;
	unsigned char	*retchar;

	if (!c)
		return (NULL);
	charlen = get_char_len(c);
	if (charlen == 0)
		return (NULL);
	if (!(retchar = (unsigned char *)pf_memalloc(charlen + 1)))
		return (NULL);
	retptr = retchar;
	char_conversion(retptr, c, charlen);
	return ((char*)retchar);
}

/*
** ft_uni_utf8_str
** -take a string of wchar_t and turn it into a char string
** of utf-8 encoded bytestrings
** -need variable for final return string
** -read the first char and convert it into its utf-8
** string and store it in return variable
** -continue along the string concatinating converted
** characters into the the return string
*/

char			*ft_uni_utf8_str(wchar_t *str)
{
	char			*retstr;
	char			*tmp;
	char			*add;
	int				index;

	index = 1;
	retstr = NULL;
	if (str && str[0] == '\0')
		return (pf_strdup("\0"));
	if (!str)
		return (NULL);
	retstr = ft_uni_utf8_char(str[0]);
	while (retstr && str[index])
	{
		tmp = pf_strdup(retstr);
		pf_memdel((void**)&retstr);
		add = ft_uni_utf8_char(str[index]);
		retstr = pf_strjoin(tmp, add);
		pf_memdel((void**)&tmp);
		pf_memdel((void**)&add);
		index++;
	}
	if (!retstr)
		return (NULL);
	return (retstr);
}
