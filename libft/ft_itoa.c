/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:06:42 by skorac            #+#    #+#             */
/*   Updated: 2018/07/26 10:11:07 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	gitlen(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	tmp;

	len = gitlen(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	if (n < 0)
		str[0] = '-';
	return (str);
}
