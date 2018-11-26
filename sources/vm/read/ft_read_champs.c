/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_champs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/07 10:04:18 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static int	ft_player_total(int ac, char **av, t_stock *s)
{
	int	i;
	int	nb_player;

	i = 0;
	nb_player = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-dump") || !ft_strcmp(av[i], "-n"))
			++i;
		else if (!ft_strcmp(av[i], "-v") || !ft_strcmp(av[i], "-a"))
			;
		else
			++nb_player;
	}
	if (nb_player > MAX_PLAYERS || !nb_player)
		return (ft_msgfdret("error number player\n", 2, 0));
	s->nb_player = nb_player;
	return (nb_player);
}

int			ft_read_champs(int ac, char **av, t_stock *s)
{
	int	index;

	s->begin_lst = NULL;
	if (!ft_player_total(ac, av, s))
		return (0);
	index = s->opt_v + s->opt_a + 1;
	if (s->opt_dump != -5)
		index += 2;
	if (index < ac && !ft_strcmp(av[index], "-n"))
		index += 2;
	while (index < ac)
	{
		if (index != -1)
			if (!ft_new_player(av[index], s))
				return (0);
		++index;
		if (index < ac && !ft_strcmp(av[index], "-n"))
			index += 2;
	}
	if (!(ft_arrange_player(ac, av, s)))
		return (0);
	return (1);
}
