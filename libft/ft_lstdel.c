/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:49:49 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 14:19:39 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *next;

	list = *alst;
	while (list)
	{
		next = list->next;
		del(((list)->content), (list)->content_size);
		free(list);
		list = next;
	}
	*alst = NULL;
}
