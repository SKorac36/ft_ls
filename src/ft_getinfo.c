/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 08:53:32 by skorac            #+#    #+#             */
/*   Updated: 2018/09/18 14:12:46 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	uid_to_name(uid_t uid)
{
	struct passwd	*getp;
	struct passwd	*pw_ptr;
	char			*numstr;

	getp = getpwuid(uid);
	pw_ptr = getp;
	if (getp == NULL)
	{
		numstr = (ft_itoa(uid));
		ft_putstr(numstr);
		free(numstr);
	}
	else
	ft_putstr(pw_ptr->pw_name);
	ft_putchar('\t');
}

void	gid_to_name(gid_t gid)
{
	struct group	*getgid;
	struct group	*grp_ptr;
	char			*numstr;

	getgid = getgrgid(gid);
	grp_ptr = getgid;
	if (getgid == NULL)
	{
		numstr = ft_itoa(gid);
		ft_putstr(numstr);
		free(numstr);
	}
	else
		ft_putstr(grp_ptr->gr_name);
	ft_putchar('\t');
}

void	time_to_name(time_t date)
{
	char		*str1;
	char		*str2;
	time_t		actualtime;

	actualtime = time(0);
	str1 = (ctime(&date));;
	if ((actualtime - 15778463) > date || actualtime < date)
{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar('\t');
	free(str1);
}
