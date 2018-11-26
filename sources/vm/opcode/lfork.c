/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:22:10 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/09 10:21:13 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x0f
*/

static int		ft_process_cpy(t_process *dest, t_process *src)
{
	int		i;

	dest->aff = NULL;
	if (src->aff != NULL && !(dest->aff = ft_strdup(src->aff)))
	{
		free(dest);
		return (0);
	}
	i = -1;
	while (++i < REG_NUMBER)
		dest->registre[i] = src->registre[i];
	dest->carry = src->carry;
	dest->id = src->id;
	dest->next = NULL;
	return (1);
}

int				ft_lfork(t_stock *s, t_process *p)
{
	t_process	*bis;

	if (!(bis = (t_process *)malloc(sizeof(t_process)))
			|| !ft_process_cpy(bis, p))
	{
		ft_putstr("lfork malloc error fork abort\n");
		return (0);
	}
	bis->next = s->begin_lst;
	s->begin_lst = bis;
	bis->pc = ft_index_pc(read_direct(2, s, p, 1), p->pc);
	bis->live = 0;
	ft_wait_instruction(bis, s->memory[bis->pc]);
	return (1);
}
