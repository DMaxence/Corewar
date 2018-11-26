/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:49:36 by tbleuse           #+#    #+#             */
/*   Updated: 2018/10/03 10:49:28 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static int		vm_verif_arg(int ac)
{
	if (ac == 1)
	{
		ft_printf("./corewar [-dump nbr_cycles] [-v]");
		ft_printf(" [[-n number] champion1.cor] ...\n");
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stock		*s;

	s = NULL;
	if (!vm_verif_arg(ac)
			|| !(s = ft_init_and_read(ac, av, s)))
	{
		return (0);
	}
	ft_execution(s);
	ft_free_memory(s);
	return (0);
}
