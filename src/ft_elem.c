/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:47:33 by skorac            #+#    #+#             */
/*   Updated: 2018/09/19 14:46:33 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_file	*elemnew(char *name, char *path, t_option opt)
{
	t_file		*new;
	struct stat	info_p;
	char		*pth;
	
	(void)opt;
	new = (t_file*)malloc(sizeof(t_file));;
	new->name = name;
	pth = ft_strjoin(path, new->name);
	new->path = pth;
	if (lstat(new->path, &info_p) == -1)
		return (NULL);
	free(pth);
	new->mode = info_p.st_mode;	
	new->time = info_p.st_mtime;
	new->usr = info_p.st_uid;
	new->grp = info_p.st_gid;
	new->lnk = ((int)info_p.st_nlink);
	new->size = ((int)info_p.st_size);
	new->blk = ((blksize_t)(info_p.st_blocks));
	new->next = NULL;
	printf("elemname:%s %p\n",new->name, new);
	return (new);

}

int		elemget(t_file **files, struct dirent *file, char *path, t_option opt)
{
	t_file *list;

	list = *files;
	if (!file)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(file->d_name, path, opt);
		list = NULL;
	}
	else
		*files = elemnew(file->d_name, path, opt);
	return (1);
}

void	elemgetfiles(t_file **files, char *name, char *path, t_option opt)
{
	t_file *list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(name, path, opt);
		list = NULL;
	}
	else
		*files = elemnew(name, path, opt);
}
