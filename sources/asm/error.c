/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:56:39 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_err g_out[17] =
{
	{ARG_ERR, "argument error\n"},
	{CRT_FAIL, ".cor creation failed\n"},
	{ERR_CLOSE, "close failed\n"},
	{ERR_OPEN, "open failed\n"},
	{ERR_TYPE, "incorrect file type\n"},
	{ETY_FILE, "empty file\n"},
	{HEAD_ERR, "header error\n"},
	{LAB_ERR, "label error\n"},
	{MLC_ERR, "allocation failed\n"},
	{NO_PRO, "no process instruction\n"},
	{OPC_ERR, "opcode error\n"},
	{PRO_ERR, "process instruction error\n"},
	{PROG_SIZE, "champion size error\n"},
	{STX_ERR, "syntax error\n"},
	{SIZE_COM, "comment size error\n"},
	{SIZE_NAME, "name size error\n"},
	{NO_ERR, NULL},
};

void			print_err(char *file, t_asm *prog)
{
	int			i;

	i = 0;
	while (g_out[i].code != NO_ERR)
	{
		if (prog->err.code == g_out[i].code)
		{
			ft_printf("file \"%s\" : %s", file, g_out[i].msg);
			break ;
		}
		i++;
	}
}
