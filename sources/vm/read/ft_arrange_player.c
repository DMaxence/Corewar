/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_champs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:20:09 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static int		ft_verif_double(int tab[MAX_PLAYERS][2])
{
	int		index;
	int		champ;

	champ = -1;
	while (++champ < MAX_PLAYERS)
		if (tab[champ][0])
		{
			index = champ;
			while (++index < MAX_PLAYERS)
				if (tab[index][0] && tab[index][1] == tab[champ][1])
					return (ft_msgfdret("same player number\n", 2, 0));
		}
	return (1);
}

static int		ft_is_in_tab(int nb, int tab[MAX_PLAYERS][2])
{
	int		index;

	index = -1;
	while (++index < MAX_PLAYERS)
	{
		if (tab[index][0] && tab[index][1] == nb)
			return (1);
	}
	return (0);
}

static int		ft_change_process_number(t_stock *s)
{
	int			i;
	t_process	*tmp;

	i = -1;
	tmp = s->begin_lst;
	while (++i < s->nb_player)
	{
		tmp->registre[0] = s->champ[i]->nb_player;
		tmp = tmp->next;
	}
	return (1);
}

static int		ft_mv_champ_number(int tab[MAX_PLAYERS][2], t_stock *s)
{
	int		index;
	int		nb;

	if (!ft_verif_double(tab))
		return (0);
	index = -1;
	nb = -1;
	while (++index < MAX_PLAYERS && s->champ[index]->nb_player)
	{
		if (tab[index][0])
		{
			ft_change_process(s->champ[index]->nb_player, tab[index][1], s);
			s->champ[index]->nb_player = tab[index][1];
		}
		else
		{
			while (ft_is_in_tab(nb, tab))
				--nb;
			ft_change_process(s->champ[index]->nb_player, nb, s);
			s->champ[index]->nb_player = nb--;
		}
	}
	return (ft_change_process_number(s));
}

int				ft_arrange_player(int ac, char **av, t_stock *s)
{
	int		i;
	int		tab[MAX_PLAYERS][2];
	int		champ;

	i = 0;
	champ = 0;
	ft_init_tab(&tab);
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-dump"))
			++i;
		else if (!ft_strcmp(av[i], "-n"))
		{
			if (tab[champ][0] || i + 2 >= ac || !ft_isint(av[i + 1]))
				return (ft_msgfdret("error flag\n", 2, 0));
			tab[champ][0] = 1;
			if ((tab[champ][1] = ft_atoi(av[i + 1])) < 0)
				return (ft_msgfdret("champ number must be positive\n", 2, 0));
			tab[champ][1] = -tab[champ][1];
			++i;
		}
		else if (ft_strcmp(av[i], "-v"))
			++champ;
	}
	return (ft_mv_champ_number(tab, s));
}
