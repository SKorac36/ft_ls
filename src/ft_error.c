/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:38:17 by skorac            #+#    #+#             */
/*   Updated: 2018/09/18 09:40:02 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_opterror(char opt)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\nusage: ft_ls [-Rafglrtu1] [file ...]\n", 2);
	exit(EXIT_FAILURE);
	exit(1);
}

void	basicerror(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}

