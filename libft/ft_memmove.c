/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:09:09 by skorac            #+#    #+#             */
/*   Updated: 2018/06/26 08:37:55 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (len--)
			p1[len] = p2[len];
	}
	else
	{
		while (i < len)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	return (p1);
}
