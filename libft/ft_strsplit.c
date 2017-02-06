/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 23:08:25 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/29 14:33:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c, int flag, int wrdstrt)
{
	int word_count;
	int index;

	word_count = 0;
	index = 0;
	if (!*s)
		return (0);
	if (s[0] != c)
	{
		word_count++;
		if (flag == 1 && wrdstrt == 1)
			return (index);
	}
	while (s[index])
	{
		if (s[index] == c && s[index + 1] != c && s[index + 1] != '\0')
			word_count++;
		index++;
		if (flag == 1 && word_count == wrdstrt)
			return (index);
	}
	return (word_count);
}

static char	*substr(char const *s, char c, int count)
{
	int		pos;
	int		wordlen;
	char	*retstr;
	int		index;

	index = 0;
	wordlen = 0;
	pos = count_words(s, c, 1, count);
	while (s[pos] != c && s[pos] != '\0')
	{
		wordlen++;
		pos++;
	}
	pos = count_words(s, c, 1, count);
	if (!(retstr = (char*)malloc(sizeof(char) * wordlen + 1)))
		return (NULL);
	while (index < wordlen)
	{
		retstr[index] = s[pos];
		index++;
		pos++;
	}
	retstr[index] = '\0';
	return (retstr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr_array;
	int		size;
	int		count;

	count = 0;
	size = count_words(s, c, 0, 0);
	if (!(ptr_array = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (count < size)
	{
		if (!(ptr_array[count] = substr(s, c, count + 1)))
			return (NULL);
		count++;
	}
	ptr_array[count] = 0;
	return (ptr_array);
}
