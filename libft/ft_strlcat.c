/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:20:11 by skorac            #+#    #+#             */
/*   Updated: 2018/06/26 08:41:15 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;
	size_t j;

	i = 0;
	k = ft_strlen(dst);
	j = ft_strlen(src);
	if (dstsize <= k)
		return (j + dstsize);
	while (dst[i] != '\0' && i < (dstsize - 1))
		i++;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (k + j);
}
