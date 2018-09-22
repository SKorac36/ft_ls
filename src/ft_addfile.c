/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 07:32:54 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:26:32 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 13:14:08 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	mode_to_letters(int mode)
{
	ft_putchar((S_ISFIFO(mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(mode)) ? 's' : '\0');
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	usr(mode);
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	grp(mode);
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
<<<<<<< HEAD
	stk(mode);
	ft_putstr("\t");
}

void	usr(int mode)
{
	if (mode & S_ISUID)
		ft_putchar('s');
	else if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	grp(int mode)
{
	if (mode & S_ISGID)
		ft_putchar('s');
	else if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	stk(int mode)
{
	if (mode & S_ISVTX)
		ft_putchar('t');
	else if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
=======
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("\t");
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
}
