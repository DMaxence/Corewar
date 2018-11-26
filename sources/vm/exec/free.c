/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:56:10 by anaroste          #+#    #+#             */
/*   Updated: 2018/10/04 11:25:58 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void	ft_free_champ(t_champ *champ)
{
	free(champ->header);
	free(champ);
}

static void	ft_free_process_list(t_process *p1)
{
	t_process	*p2;

	if (!p1)
		return ;
	p2 = p1->next;
	while (p2)
	{
		ft_strdel(&p1->aff);
		free(p1);
		p1 = p2;
		p2 = p2->next;
	}
	ft_strdel(&p1->aff);
	free(p1);
}

void		ft_free_memory(t_stock *s)
{
	int		i;

	if (s)
	{
		if (s->champ)
		{
			i = -1;
			while (++i < MAX_PLAYERS)
			{
				ft_free_champ(s->champ[i]);
			}
			free(s->champ);
		}
		ft_free_process_list(s->begin_lst);
		free(s);
	}
}
