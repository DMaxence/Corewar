/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_player_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:10:06 by tbleuse           #+#    #+#             */
/*   Updated: 2018/09/07 11:42:47 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void		ft_change_process(int before, int new_nb, t_stock *s)
{
	t_process	*tmp;

	tmp = s->begin_lst;
	while (tmp)
	{
		if (tmp->registre[1] == before)
			tmp->registre[1] = new_nb;
		tmp = tmp->next;
	}
}

void		ft_init_tab(int (*tab)[MAX_PLAYERS][2])
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		(*tab)[i][0] = 0;
		(*tab)[i][1] = 0;
	}
}
