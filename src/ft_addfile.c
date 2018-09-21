/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 07:32:54 by skorac            #+#    #+#             */
/*   Updated: 2018/09/21 13:14:08 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

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
	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("\t");
}
