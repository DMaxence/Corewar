/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:22:10 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 11:21:25 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x10
*/

static char		ft_verif_ocp(char ocp)
{
	if ((ocp & 0xc0) >> 6 != REG_CODE
			|| (ocp & 0x30) >> 4 != 0
			|| (ocp & 0x0c) >> 2 != 0
			|| (ocp & 0x03) != 0)
		return (0);
	return (ocp);
}

static int		ft_special_aff(t_process *p, char c)
{
	int			length;
	char		*tmp;

	if (!c)
	{
		write(1, p->aff, ft_strlen(p->aff) + 1);
		ft_strdel(&p->aff);
		p->aff = NULL;
		return (1);
	}
	length = ft_strlen(p->aff);
	if (!(tmp = (char *)malloc(sizeof(char) * (length + 2))))
		return (0);
	ft_memcpy(tmp, p->aff, length);
	tmp[length] = c;
	tmp[length + 1] = '\0';
	ft_strdel(&p->aff);
	p->aff = tmp;
	return (1);
}

int				ft_aff(t_stock *s, t_process *p)
{
	char		c[2];

	if (!ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE])
			|| !ft_verif_reg(s->memory[(p->pc + 2) % MEM_SIZE]))
		return (0);
	c[0] = (p->registre[(int)s->memory[(p->pc + 2) % MEM_SIZE] - 1]) % 256;
	p->carry = 0;
	if (!c[0])
		p->carry = 1;
	if (s->opt_a)
		return (ft_special_aff(p, c[0]));
	c[1] = '\n';
	write(1, c, 2);
	return (1);
}
