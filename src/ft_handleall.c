/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:33:27 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:27:37 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 13:37:27 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_simple(t_option arg, t_file *files)
{
	t_file *cur;

	cur = files;
	while (cur)
	{
		if (!(arg.option_a == 0 && cur->name[0] == '.'))
			ft_putendl(cur->name);
		free(&cur->name);
		cur = cur->next;
	}
}

void	put_size(t_file *files, t_option opt)
{
	ft_putstr("total ");
	ft_putnbr(get_size(files, opt));
	ft_putchar('\n');
}

void	ls_long(t_option arg, t_file *files)
{
	t_file	*cur;

	cur = files;
	put_size(files, arg);
	while (cur)
	{
		if (!(arg.option_a == 0 && cur->name[0] == '.'))
		{
			mode_to_letters(cur->mode);
			ft_putnbr(cur->lnk);
			ft_putchar('\t');
			uid_to_name(cur->usr);
			gid_to_name(cur->grp);
			ft_putnbr(cur->size);
			ft_putchar('\t');
			time_to_name(cur->time);
			ft_putstr(cur->name);
			if (S_ISLNK(cur->mode))
				ft_islink(cur);
			ft_putchar('\n');
		}
		free(&cur->name);
		cur = cur->next;
	}
}
