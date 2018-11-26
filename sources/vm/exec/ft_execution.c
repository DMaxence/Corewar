/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:45:17 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"
#include "../../../includes/visu.h"

static void		ft_execution_bis(t_stock *s, t_process *p, int *tmp)
{
	if (s->opt_v)
		ft_refresh_memory(s);
	while (p)
	{
		if (p->wait > 0)
			--p->wait;
		else
		{
			ft_execute_instruction(s, p);
			if (!p->wait)
			{
				ft_next_instruction(s, p, s->memory[p->pc]);
				ft_wait_instruction(p, s->memory[p->pc]);
			}
		}
		p = p->next;
	}
	if (*tmp >= s->cycle_to_die)
	{
		*tmp = 0;
		ft_cycle_to_die(s);
	}
}

int				ft_execution(t_stock *s)
{
	t_process	*p;
	int			tmp;

	tmp = 0;
	ft_first_play(s);
	if (s->opt_v)
		ft_print_memory(s);
	while (s->cycle > -1 && s->cycle != s->opt_dump)
	{
		++s->cycle;
		tmp++;
		p = s->begin_lst;
		ft_execution_bis(s, p, &tmp);
	}
	if (s->opt_v)
		ft_close_win(s);
	else if (s->cycle == s->opt_dump)
		ft_print_dump(s);
	return (1);
}
