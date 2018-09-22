/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:30:26 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:49:51 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 13:35:53 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		one_of(char c, char *str)
{
	int	i;

	if (str == NULL || c == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}

int		analize_str(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

void	get_arg(t_option *arg, char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (one_of(str[i], MOD_OPT) || (str[1] == '-' && !str[2]))
		{
			arg->option_l = (str[i] == 'l' ? 1 : arg->option_l);
			arg->option_a = (str[i] == 'a' ? 1 : arg->option_a);
			arg->option_r = (str[i] == 'r' ? 1 : arg->option_r);
			arg->option_t = (str[i] == 't' ? 1 : arg->option_t);
			arg->option_1 = (str[i] == '1' ? 1 : arg->option_1);
		}
		else
			ft_opterror(str[i]);
	}
}

void	get_param(int nb, char **param, t_option *arg, t_list **path)
{
	int	i;
	int	type;

	i = -1;
	type = 1;
	while (++i < nb)
	{
		if (analize_str(param[i + 1]) == 0)
			type = 0;
		if (type == 1)
			get_arg(arg, param[i + 1]);
		else if (type == 0)
			ft_lstpushback(path, param[i + 1], ft_strlen(param[i + 1]));
	}
}

<<<<<<< HEAD
int		main(int argc, char **argv)
=======
void	delete_content(void *info, size_t size)
{
	free(info);
	info = NULL;

	(void)size;
}

void	erase_list(t_list **directories)
{
	void	(*del)(void *, size_t);

	del = &delete_content;
	ft_lstdel(directories, del);
}

int		main(int ac, char **av)
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
{
	t_option	arg;
	t_list		*path;

	arg = (t_option){0, 0, 0, 0, 0};
	path = NULL;
	if (argc > 1)
		get_param(argc - 1, argv, &arg, &path);
	if (path == NULL)
<<<<<<< HEAD
		path = ft_lstnew(".", 1);
	justdoit(arg, path);
=======
		path = ft_lstnew(".", 1);		
	core(arg, path);
	sleep(6);
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
	return (0);
}
