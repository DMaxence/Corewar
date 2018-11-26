/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:00:49 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/16 20:23:09 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_putchar(char c)
{
	write(1, &c, 1);
}

void	pf_putstr(const char *str)
{
	write(1, str, pf_strlen(str));
}

void	pf_putnstr(char *str, int n)
{
	if (n <= 0)
		return ;
	if (n < (int)pf_strlen(str))
		write(1, str, n);
	else
		write(1, str, pf_strlen(str));
}

void	pf_put_nb_max(intmax_t nb)
{
	if (nb < 0)
	{
		pf_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		pf_putchar((nb % 10) + '0');
	if (nb >= 10)
	{
		pf_put_nb_max(nb / 10);
		pf_putchar((nb % 10) + '0');
	}
}

void	pf_put_u_nb_max(uintmax_t nb)
{
	if (nb < 10)
		pf_putchar((nb % 10) + '0');
	if (nb >= 10)
	{
		pf_put_u_nb_max(nb / 10);
		pf_putchar((nb % 10) + '0');
	}
}
