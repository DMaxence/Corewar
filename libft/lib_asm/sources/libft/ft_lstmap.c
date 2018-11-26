/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:24:11 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/20 11:34:52 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*init;

	fresh = NULL;
	init = NULL;
	if (lst)
	{
		fresh = ft_lstnew(lst->content, lst->content_size);
		fresh = (*f)(lst);
		init = fresh;
		lst = lst->next;
		while (lst)
		{
			fresh->next = ft_lstnew(lst->content, lst->content_size);
			fresh->next = (*f)(lst);
			fresh = fresh->next;
			lst = lst->next;
		}
		fresh->next = NULL;
	}
	return (init);
}
