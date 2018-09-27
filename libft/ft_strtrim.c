/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:37:38 by skorac            #+#    #+#             */
/*   Updated: 2018/06/26 08:50:08 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (s)
	{
		i = 0;
		j = 0;
		len = (int)ft_strlen(s);
		while (s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
			len--;
		while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
			i++;
		if (len < i)
			len = -1;
		if (!(ret = ft_strnew(len + 1)))
			return (NULL);
		while (i < len)
			ret[j++] = s[i++];
		ret[j] = '\0';
		return (ret);
	}
	return (NULL);
}
