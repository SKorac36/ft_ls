/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:24:28 by skorac            #+#    #+#             */
/*   Updated: 2018/09/22 13:28:14 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

blksize_t	get_size(t_file *list, t_option opt)
{
	t_file		*tmp;
	blksize_t	ret;

	ret = 0;
	tmp = list;
	if (opt.option_a == 0)
		while (tmp)
		{
			if ((tmp->name && tmp->name[0] != '.'))
				ret += tmp->blk;
			tmp = tmp->next;
		}
	else if (opt.option_a == 1)
		while (tmp)
		{
			if (tmp->name)
				ret += tmp->blk;
			tmp = tmp->next;
		}
	return (ret);
}
