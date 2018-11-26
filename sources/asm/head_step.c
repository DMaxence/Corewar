/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:59:57 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int					fill_magic(t_asm *prog)
{
	char					magic[10];
	char					mag[3];

	ft_sprintf(magic, "%08x", prog->head.magic);
	while (prog->i < 4)
	{
		ft_strncpy(mag, magic + prog->i * 2, 2);
		prog->cor[prog->i] = ft_atobase(mag, "0123456789abcdef");
		ft_bzero(mag, 3);
		prog->i++;
	}
	return (0);
}

static int					fill_name(t_asm *prog)
{
	int						j;

	j = 0;
	while (j < prog->head.name_len)
	{
		prog->cor[prog->i] = prog->head.name[j];
		j++;
		prog->i++;
	}
	prog->i = PROG_NAME_LENGTH;
	return (0);
}

static int					fill_prog_size(t_asm *prog)
{
	int						i;
	int						j;
	char					size[5];
	char					split[3];

	i = 0;
	ft_sprintf(size, "%04x", prog->head.prog_size);
	prog->i += 10;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			split[j] = size[i * 2 + j];
			j++;
		}
		prog->cor[prog->i] = ft_atobase(split, "0123456789abcdef");
		ft_bzero(split, 3);
		i++;
		prog->i++;
	}
	return (0);
}

static int					fill_comment(t_asm *prog)
{
	int						j;

	j = 0;
	while (j < prog->head.com_len)
	{
		prog->cor[prog->i] = prog->head.comment[j];
		j++;
		prog->i++;
	}
	prog->i = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	return (0);
}

int							head_step(t_asm *prog)
{
	if (fill_magic(prog))
		return (1);
	if (fill_name(prog))
		return (1);
	if (fill_prog_size(prog))
		return (1);
	if (fill_comment(prog))
		return (1);
	return (0);
}
