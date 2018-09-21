/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:21:35 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 14:42:51 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_free(t_file *file)
{
	free(file->name);
	free(file->path);
	free(file);
}

void	del(void *d, size_t s)
{
	d = NULL;
	s = 0;
}

void	lstfree(t_list **lst)
{
	ft_lstdel(lst, &del);
	free(*lst);
}
