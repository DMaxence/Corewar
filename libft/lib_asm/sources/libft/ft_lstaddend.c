/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:37:54 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/14 16:56:52 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstaddend(t_list *begin, t_list *add)
{
	t_list	*lst;

	lst = begin;
	while (lst->next)
		lst = lst->next;
	lst->next = add;
	return (begin);
}
