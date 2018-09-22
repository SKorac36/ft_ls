/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:21:35 by skorac            #+#    #+#             */
/*   Updated: 2018/09/22 13:27:18 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	delete_content(void *info, size_t size)
{
	free(info);
	info = NULL;
	(void)size;
}

void	erase_list(t_list **directories)
{
	void	(*del)(void *, size_t);

	del = &delete_content;
	ft_lstdel(directories, del);
}

void	destroyevidence(t_list *a, t_list *b, t_list *c)
{
	if (a)
		erase_list(&a);
	if (b)
		erase_list(&b);
	if (c)
		erase_list(&c);
}
