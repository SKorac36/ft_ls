/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:07:12 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 14:44:28 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_islink(t_file *file)
{
	char			*buf;
	struct stat		stats;
	size_t			nbytes;
	size_t			bufsiz;

	lstat(file->name, &stats);
	bufsiz = file->size + 1;
	if (file->size == 0)
		bufsiz = 0;
	buf = (char *)malloc(sizeof(char *) * bufsiz);
	nbytes = readlink(file->name, buf, bufsiz);
	ft_putstr(" -> ");
	if (buf[0] == '.')
		file->blk -= bufsiz;
	ft_putstr(buf);
	
	free(buf);

}
