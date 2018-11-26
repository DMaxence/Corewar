/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:53:15 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/21 13:33:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

t_process	*ft_key_right(t_process *lst, t_stock *s)
{
	if (lst)
	{
		if (lst->next)
			lst = lst->next;
		if (lst->next)
			mvprintw(65, BEGIN_DETAILS + 2, "                   ");
		else
			mvprintw(65, BEGIN_DETAILS + 2, "END LIST           ");
	}
	ft_print_process(lst, s, 43);
	return (lst);
}

t_process	*ft_key_up(t_process *lst, t_stock *s)
{
	ft_print_process(lst, s, 43);
	mvprintw(65, BEGIN_DETAILS + 2, "BEGIN LIST         ");
	return (lst);
}

void		ft_key_down(void)
{
	int		i;

	i = 42;
	while (++i <= 65)
		mvprintw(i, BEGIN_DETAILS, "                                       ");
}
