/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/05 12:18:51 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void		ft_wait_instruction(t_process *p, char inst)
{
	if (inst == 0x10)
		p->wait = 1;
	else if (inst == 0x02 || inst == 0x03)
		p->wait = 4;
	else if (inst == 0x06 || inst == 0x07 || inst == 0x08)
		p->wait = 5;
	else if (inst == 0x01 || inst == 0x04 || inst == 0x05 || inst == 0x0d)
		p->wait = 9;
	else if (inst == 0x09)
		p->wait = 19;
	else if (inst == 0x0a || inst == 0x0b)
		p->wait = 24;
	else if (inst == 0x0e)
		p->wait = 49;
	else if (inst == 0x0c)
		p->wait = 799;
	else if (inst == 0x0f)
		p->wait = 999;
	else
		p->wait = 0;
}
