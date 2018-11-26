/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:10:17 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/09 12:16:04 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

int		ft_index_pc(int index, int pc)
{
	int		new_index;

	new_index = (index + pc) % MEM_SIZE;
	if (new_index < 0)
		new_index += MEM_SIZE;
	return (new_index);
}

int		ft_idx(int index)
{
	return (index % IDX_MOD);
}

int		ft_change_vm_zaz(int nb)
{
	int		full;

	full = 0;
	if ((nb >> 31) & 1)
		full = 0x0000ffff;
	nb = (nb >> 16) & 0x0000ffff;
	return (nb | full);
}

int		ft_verif_reg(int registre)
{
	if (registre > REG_NUMBER
			|| registre <= 0)
		return (0);
	return (1);
}
