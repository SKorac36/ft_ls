/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:30:33 by skorac            #+#    #+#             */
/*   Updated: 2018/07/14 12:31:32 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putoctal(unsigned int n)
{
	if (n >= 8)
	{
		ft_putoctal(n / 8);
		ft_putoctal(n % 8);
	}
	else
		ft_putchar(n + 48);
}
