/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:51:25 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 15:24:12 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

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

char	*ft_linked(char *path)
{
	return (ft_strjoin(path, "/"));
}

void	do_ls_dir2(t_option opt, t_file *dirlist, int multidir)
{
	DIR		*dir;

	t_file	*files;
	int		first;
	char	*lnk;	
	char 	*cln;	
	first = 0;
	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);	
		lnk = ft_linked(dirlist->path);
		while (elemget(&files, readdir(dir), lnk, opt) != 0)
			;
		closedir(dir);
		if (files)
		{
			first == 1 ? ft_putchar('\n') : NULL;
			cln = ft_strjoin(dirlist->name, ":");
			multidir ? ft_putendl(cln) : NULL;
			first = 1;
			display_file(opt, files, 1);
		}
		files = NULL;
		free(lnk);
		free(cln);
		dirlist = dirlist->next;
	}
	printf("dirlist: %p\n", dirlist);
}

void	do_ls_dir(t_option opt, t_list *path, int multidir)
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
	do_ls_dir2(opt, dirlist, multidir);
	erase_list(&cur);
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

void	core(t_option opt, t_list *path, int multidir)
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
		//free(&cur->content);
		//free(&cur);
		//erase_list(&cur);
		cur = cur->next;
	}
	file ? do_ls_file(opt, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? do_ls_dir(opt, directory, multidir) : NULL;
	erase_list(&directory);
	erase_list(&file);
	erase_list(&cur);
}
