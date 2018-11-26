/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uhex_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:27:29 by bvigne            #+#    #+#             */
/*   Updated: 2018/01/23 13:33:49 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_uhex_maj(unsigned int nb)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (nb >= 16)
		ft_put_uhex_maj(nb / 16);
	ft_putchar(str[nb % 16]);
}
