/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:07:12 by skorac            #+#    #+#             */
/*   Updated: 2018/09/22 13:27:48 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_islink(t_file *file)
{
	char			*buf;
	size_t			nbytes;
	size_t			bufsiz;

	bufsiz = file->size + 1;
	if (file->size == 0)
		bufsiz = 0;
	buf = (char *)malloc(sizeof(char *) * bufsiz);
	nbytes = readlink(file->name, buf, bufsiz);
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}
