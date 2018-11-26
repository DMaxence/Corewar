/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:51:38 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/23 18:54:27 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int n)
{
	if (n <= 0)
		return ;
	if (n < (int)ft_strlen(str))
		write(1, str, n);
	else
		write(1, str, ft_strlen(str));
}
