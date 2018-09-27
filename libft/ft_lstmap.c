/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:49:48 by skorac            #+#    #+#             */
/*   Updated: 2018/06/12 10:41:23 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;

	head = f(lst);
	if (head == NULL)
		return (NULL);
	tmp = head;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (head);
}
