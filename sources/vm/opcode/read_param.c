/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:10:17 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/21 15:17:17 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

int				read_direct(int to_read, t_stock *s, t_process *p, int start)
{
	unsigned int		value;

	value = 0;
	if ((start = (start + p->pc) % MEM_SIZE) < 0)
		start += MEM_SIZE;
	if (to_read == 4)
	{
		value += (unsigned char)s->memory[(start + 3) % MEM_SIZE];
		value += (unsigned char)(s->memory[(start + 2) % MEM_SIZE]) << 8;
		value += (unsigned char)(s->memory[(start + 1) % MEM_SIZE]) << 16;
		value += (unsigned char)(s->memory[(start + 0) % MEM_SIZE]) << 24;
	}
	else if (to_read == 2)
	{
		value += (unsigned char)s->memory[(start + 1) % MEM_SIZE];
		value += (unsigned char)(s->memory[(start + 0) % MEM_SIZE]) << 8;
		value = (int)(short)value;
	}
	if (value > 2147483647)
		return ((int)(value - 4294967296));
	return ((int)value);
}

int				read_index(t_stock *s, t_process *p, int start, char idx)
{
	int		index;

	if ((start = start % MEM_SIZE) < 0)
		start += MEM_SIZE;
	index = read_direct(2, s, p, start) % MEM_SIZE;
	if (idx == 1)
		index = ft_idx(index);
	return (read_direct(4, s, p, index));
}
