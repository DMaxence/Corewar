/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:38:19 by anaroste          #+#    #+#             */
/*   Updated: 2018/10/18 14:13:43 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void	ft_putstr_v(t_stock *s, char *str)
{
	if (s->opt_v == 0)
		ft_putstr(str);
}

void	ft_putnbr_v(t_stock *s, int nb)
{
	if (s->opt_v == 0)
		ft_putnbr(nb);
}

void	ft_putnbr_n_v(t_stock *s, int nb)
{
	if (s->opt_v == 0)
		ft_putnbr_n(nb);
}
