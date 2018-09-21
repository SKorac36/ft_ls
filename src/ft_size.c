/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:24:28 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 13:55:12 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

blksize_t	get_size(t_file *list)
{
	t_file		*tmp;
	blksize_t	ret;

	ret = 0;
	tmp = list;
	while (tmp)
	{
		ret += tmp->blk;
		tmp = tmp->next;
	}
	return (ret);
}
