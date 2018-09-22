/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:35:15 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:26:42 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 10:47:15 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_cmp(t_file *a, t_file *b)
{
	int	ret;

	ret = ft_strcmp(a->name, b->name);
	return (ret);
}

int	ft_revcmp(t_file *a, t_file *b)
{
	int ret;

	ret = ft_strcmp(a->name, b->name);
	return (-ret);
}

int	ft_cmptime(t_file *a, t_file *b)
{
	return (a->time < b->time);
}

int	ft_revcmptime(t_file *a, t_file *b)
{
	return (a->time > b->time);
}
