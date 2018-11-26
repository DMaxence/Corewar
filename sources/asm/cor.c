/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:56:20 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				create_cor(char *file, t_asm *prog)
{
	char			*cor;

	cor = NULL;
	if (!(cor = (char*)malloc(sizeof(char) * ft_strlen(file) + 3)))
	{
		prog->err.code = MLC_ERR;
		return ;
	}
	cor = ft_strncpy(cor, file, ft_strlen(file) - 1);
	cor[ft_strlen(file) - 1] = 'c';
	cor[ft_strlen(file)] = 'o';
	cor[ft_strlen(file) + 1] = 'r';
	cor[ft_strlen(file) + 2] = '\0';
	if ((prog->fd = open(cor, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
	{
		ft_strdel(&cor);
		prog->err.code = CRT_FAIL;
		return ;
	}
	write(prog->fd, prog->cor, prog->cor_size);
	ft_strdel(&cor);
	if (close(prog->fd) < 0)
		prog->err.code = ERR_CLOSE;
}
