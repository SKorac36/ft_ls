/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:51:25 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:49:32 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 13:50:32 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
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
<<<<<<< HEAD
	char	*lnk;

	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);
=======
	int		first;
	char	*lnk;	
	
	first = 0;
	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);	
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
		lnk = ft_strjoin(dirlist->name, "/");
		while (elemget(&files, readdir(dir), lnk, opt) != 0)
			;
		if (files)
<<<<<<< HEAD
			display_file(opt, files, 1);
=======
		{
			first == 1 ? ft_putchar('\n') : NULL;
			first = 1;
			display_file(opt, files, 1);
		}
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
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

<<<<<<< HEAD
void	justdoit(t_option opt, t_list *path)
=======
void	core(t_option opt, t_list *path)
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
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
<<<<<<< HEAD
	destroyevidence(file, cur, directory);
=======
	erase_list(&directory);
	erase_list(&file);
	erase_list(&cur);
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
}
