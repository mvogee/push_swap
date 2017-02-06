/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:49:10 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/30 22:58:41 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content_size = content_size;
		if (!(list->content = malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
