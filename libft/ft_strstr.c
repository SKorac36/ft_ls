/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:04:34 by skorac            #+#    #+#             */
/*   Updated: 2018/06/26 08:42:19 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_match(const char *haystack, const char *needle)
{
	size_t index;

	index = 0;
	while (needle[index])
	{
		if (needle[index] != haystack[index])
			return (0);
		index++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t index;

	index = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[index] != '\0')
	{
		if (haystack[index] == needle[0])
		{
			if (ft_match(&haystack[index], needle) == 1)
				return ((char*)&haystack[index]);
		}
		index++;
	}
	return (NULL);
}
