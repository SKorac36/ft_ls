/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:11:35 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:28:22 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 13:37:08 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_sortfiles(t_file *list, t_option opt)
{
	t_file	*new;

	if (!list)
		return (NULL);
	new = list;
	sort(&new, ft_cmp);
	if (opt.option_t == 1)
	{
		if (opt.option_r == 1)
			sort(&new, ft_revcmptime);
		else
			sort(&new, ft_cmptime);
	}
	else
		opt.option_r == 1 ? sort(&new, ft_revcmp) : NULL;
	return (new);
}

void	elem_cpy(t_file **src, t_file *cpy)
{
	(*src)->name = cpy->name;
	(*src)->mode = cpy->mode;
	(*src)->path = cpy->path;
	(*src)->time = cpy->time;
	(*src)->grp = cpy->grp;
	(*src)->usr = cpy->usr;
	(*src)->lnk = cpy->lnk;
	(*src)->size = cpy->size;
}

void	swap_elem(t_file **a, t_file **b)
{
	t_file	tmp;

	tmp = **a;
	elem_cpy(a, *b);
	elem_cpy(b, &tmp);
}

void	sort(t_file **list, int (*cmp)(t_file *elem1, t_file *elem2))
{
	t_file	*a;
	t_file	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				swap_elem(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
	list = NULL;
}
