/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:43:30 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/15 17:38:10 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base(int n, int base)
{
	if (n == -2147483648)
	{
		ft_putnbr_base(n / base, base);
		-(n % base) < 10 ? ft_putchar(-(n % base) + '0') :
		ft_putchar(-(n % base) + '7');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < base && (n % base) < 10)
			ft_putchar((n % base) + '0');
		else if (n < base && (n % base) > 9)
			ft_putchar((n % base) + '7');
		if (n >= base)
		{
			ft_putnbr_base(n / base, base);
			(n % base) < 10 ? ft_putchar((n % base) + '0') :
			ft_putchar((n % base) + '7');
		}
	}
}
