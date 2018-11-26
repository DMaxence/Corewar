/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_ocp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:37:19 by anaroste          #+#    #+#             */
/*   Updated: 2018/09/20 13:51:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	return 1 -> registre
**	return 2 -> direct
**	return 3 -> index
*/

char	translate_ocp(char ocp, int arg)
{
	if (arg == 1)
		return ((ocp & 0x0c) >> 2);
	else if (arg == 2)
		return ((ocp & 0x30) >> 4);
	else if (arg == 3)
		return ((ocp & 0xc0) >> 6);
	return (0x00);
}
