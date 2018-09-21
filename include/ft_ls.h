/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:45:59 by skorac            #+#    #+#             */
/*   Updated: 2018/09/21 13:05:08 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"
# define MOD_OPT "lart1"

typedef struct 		s_option
{
	int option_a;
	int	option_l;
	int option_r;
	int option_t;
	int option_1;
}					t_option;

typedef struct		s_file
{
	
	char			*name;
	char			*path;
	int				mode;
	time_t			time;
	gid_t			grp;
	uid_t 			usr;
	int				lnk;
	int				size;
	blkcnt_t		blk;
	struct s_file	*next;

}					t_file;
void		basicerror(char *name, char *err, int ex);
void		memoryfree(t_file *files);
void		ft_del(t_list *elem);
void		lstfree(t_list **lst);
void		mode_to_letters(int mode);
void		uid_to_name(uid_t uid);
void		gid_to_name(gid_t gid);
void		time_to_name(time_t date);
void		ft_opterror(char opt);
void		ft_error(char *name, int err);
int			ft_cmp(t_file *a, t_file *b);
int			ft_revcmp(t_file *a, t_file *b);
int			ft_cmptime(t_file *a, t_file *b);
int			ft_revcmptime(t_file *a, t_file *b);
t_file  	*ft_sortfiles(t_file *list, t_option opt);
void    	elem_cpy(t_file **src, t_file *cpy);
void    	swap_elem(t_file **a, t_file **b);
void    	sort(t_file **list, int (*cmp)(t_file *elem1, t_file *elem2));
t_file		*elemnew(char *name, char *path, t_option opt);
int			elemget(t_file **files, struct dirent *file, char *path, t_option opt);
void		elemgetfiles(t_file **files, char *name, char *path, t_option opt);
void		ls_simple(t_option opt, t_file *files);
void		ls_long(t_option opt, t_file *cur);
void		core(t_option opt, t_list *path);
blksize_t	get_size(t_file *list);
void		ft_islink(t_file *file);
void		display_file(t_option opt, t_file *files, int type);
void		do_ls_dir2(t_option opt, t_file *dirlist);
void		do_ls_dir(t_option opt, t_list *path);
void		do_ls_file(t_option opt, t_list *path);
void		put_size(t_file *files);
int			one_of(char c, char *str);
int			analize_str(char *str);
void		get_arg(t_option *arg, char *str);
void		get_param(int nb, char **param, t_option *arg, t_list **path);
void		ft_freelist(void *to_delete, size_t size);
void		erase_list(t_list **direrctories);
void		ft_free(t_file *file);
#endif
