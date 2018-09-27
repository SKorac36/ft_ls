/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:54:57 by skorac            #+#    #+#             */
/*   Updated: 2018/06/26 08:48:35 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*new;
	size_t	len;
	size_t	i;

	if (s && f)
	{
		len = ft_strlen(s);
		new = ft_strnew(len);
		i = 0;
		if (!new)
			return (NULL);
		while (s[i])
		{
			new[i] = (*f)(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
