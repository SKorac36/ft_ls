/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:51:25 by skorac            #+#    #+#             */
/*   Updated: 2018/09/22 13:49:32 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display_file(t_option opt, t_file *files, int type)
{
	t_file *cur;

	cur = files;
	cur = ft_sortfiles(cur, opt);
	(void)type;
	if (opt.option_l == 1)
		ls_long(opt, cur);
	else if (opt.option_1 == 1 || opt.option_l == 0)
		ls_simple(opt, cur);
}

void	do_ls_dir2(t_option opt, t_file *dirlist)
{
	DIR		*dir;
	t_file	*files;
	char	*lnk;

	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		lnk = ft_strjoin(dirlist->name, "/");
		while (elemget(&files, readdir(dir), lnk, opt) != 0)
			;
		if (files)
			display_file(opt, files, 1);
		dirlist = dirlist->next;
	}
	free(lnk);
	closedir(dir);
}

void	do_ls_dir(t_option opt, t_list *path)
{
	t_list *cur;
	t_file *dirlist;

	cur = path;
	dirlist = NULL;
	while (cur)
	{
		elemgetfiles(&dirlist, cur->content, "", opt);
		cur = cur->next;
	}
	dirlist = ft_sortfiles(dirlist, opt);
	do_ls_dir2(opt, dirlist);
	erase_list(&cur);
	free(&dirlist->name);
}

void	do_ls_file(t_option opt, t_list *path)
{
	t_list *cur;
	t_file *files;

	cur = path;
	files = NULL;
	opt.option_a = 1;
	while (cur)
	{
		elemgetfiles(&files, cur->content, "", opt);
		cur = cur->next;
	}
	if (files)
		display_file(opt, files, 0);
}

void	justdoit(t_option opt, t_list *path)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*cur;

	file = NULL;
	directory = NULL;
	cur = path;
	while (cur)
	{
		if ((dir = opendir(cur->content)) == NULL)
			errno != ENOTDIR ? basicerror("ft_ls: ", cur->content, 0) : \
				ft_lstpushback(&file, cur->content, cur->content_size);
		else
		{
			ft_lstpushback(&directory, cur->content, cur->content_size);
			if (closedir(dir) == -1)
				basicerror("ft_ls: ", cur->content, 0);
		}
		cur = cur->next;
	}
	file ? do_ls_file(opt, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? do_ls_dir(opt, directory) : NULL;
	destroyevidence(file, cur, directory);
}
