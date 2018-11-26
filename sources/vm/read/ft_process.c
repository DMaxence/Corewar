/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/01 17:31:59 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void		ft_crash(t_stock *s, t_process *prev, t_process *process)
{
	if (!prev)
		s->begin_lst = s->begin_lst->next;
	else
		prev->next = process->next;
	free(process);
}

static void	ft_new_process_init_var(t_process *new_process, int pc, int r1)
{
	new_process->carry = 0;
	new_process->registre[0] = r1;
	new_process->pc = pc;
	new_process->old_pc = pc;
	new_process->wait = 0;
	new_process->live = 0;
	new_process->id = r1;
	new_process->aff = NULL;
	new_process->next = NULL;
}

int			ft_new_process(short pc, int push_in_r1, t_stock *s)
{
	t_process	*new_process;
	t_process	*tmp;

	if (!(new_process = (t_process*)malloc(sizeof(t_process))))
		return (ft_msgfdret("error malloc\n", 2, 0));
	ft_new_process_init_var(new_process, pc, push_in_r1);
	if (s->begin_lst)
	{
		tmp = s->begin_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_process;
	}
	else
		s->begin_lst = new_process;
	return (1);
}
