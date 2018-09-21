/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:42:26 by skorac            #+#    #+#             */
/*   Updated: 2018/07/13 11:51:48 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_double(double d, double y)
{
	if (d >= 10)
	{
		ft_double(((long)d / 10) + (d - (long)d), y);
		ft_double((long)d % 10, y);
	}
	else if (d - (long)d > y && d - (long)d < 1 - y)
		ft_double((long)((d - (long)d) / (y)), y);
	else
		ft_putchar((long)d + 48);
}

void		ft_putdouble(double d, double y)
{
	if (d < 0)
	{
		ft_putchar('-');
		d *= -1;
	}
	if (d - (long)d < 1 - y)
		ft_double((long)d, y);
	ft_putchar('.');
	ft_double(d - (long)d, y);
}
