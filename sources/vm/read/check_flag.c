/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:49:36 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/07 12:15:44 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	ajout d'une option -v pour visu
**	check_flag check les differents flags present
**	je n'ai pas gere l'option -n je ne comprend pas comment elle marche
*/

static int		flag_a(t_stock *s)
{
	if (s->opt_a)
		return (ft_msgfdret("error flag -a\n", 2, 0));
	s->opt_a = 1;
	return (1);
}

static int		flag_v(t_stock *s)
{
	if (s->opt_v)
		return (ft_msgfdret("error flag -v\n", 2, 0));
	s->running = 0;
	s->opt_v = 1;
	return (1);
}

static int		flag_d(int *index, int ac, char **av, t_stock *s)
{
	if (*index + 1 < ac)
	{
		if (s->opt_dump != -5 || !ft_isint(av[*index + 1])
				|| (s->opt_dump = ft_atoi(av[*index + 1])) < 0)
			return (ft_msgfdret("error flag -dump\n", 2, 0));
		++*index;
	}
	else
		return (ft_msgfdret("-dump invalid\n", 2, 0));
	return (1);
}

int				check_flag(int ac, char **av, t_stock *s)
{
	int		index;

	index = 1;
	while (index < ac && av[index][0] == '-')
	{
		if ((!ft_strcmp(av[index], "-a") && !flag_a(s))
				|| (!ft_strcmp(av[index], "-v") && !flag_v(s))
				|| (!ft_strcmp(av[index], "-dump")
					&& !flag_d(&index, ac, av, s)))
			return (0);
		++index;
	}
	return (1);
}
