/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:42:30 by skorac            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/22 13:55:26 by skorac           ###   ########.fr       */
=======
/*   Updated: 2018/09/21 10:43:31 by skorac           ###   ########.fr       */
>>>>>>> f3de50c6ed15094e78a22e7f16d73347b60f3200
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstpushback(t_list **blst, void const *content,
        size_t content_size)
{
    t_list  *list;

    list = *blst;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_lstnew(content, content_size);
    }
    else
        *blst = ft_lstnew(content, content_size);
}
