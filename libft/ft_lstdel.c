/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:48:03 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/01 13:33:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;
	t_list *listpos;

	listpos = *alst;
	while (listpos)
	{
		nxt = listpos->next;
		del(listpos->content, listpos->content_size);
		free(listpos);
		listpos = nxt;
	}
	*alst = NULL;
}
