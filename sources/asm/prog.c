/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/22 15:15:54 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int			usage(void)
{
	ft_printf("usage: ./asm [file ...]\n");
	return (0);
}

static void			init_prog(t_asm *prog)
{
	prog->fd = -1;
	prog->err.code = NO_ERR;
	prog->err.msg = NULL;
	prog->head.magic = COREWAR_EXEC_MAGIC;
	prog->head.name_len = 0;
	ft_bzero(prog->head.name, PROG_NAME_LENGTH + 1);
	prog->head.com_len = 0;
	ft_bzero(prog->head.comment, COMMENT_LENGTH + 1);
	prog->head.prog_size = 0;
	prog->head.end = 0;
	prog->line = 0;
	prog->pro = NULL;
	prog->byte = NULL;
	prog->cor = NULL;
	prog->i = 0;
	prog->cor_size = 0;
}

static void			reset_prog(t_asm *prog)
{
	free_prog(prog);
	prog->fd = -1;
	prog->err.code = NO_ERR;
	prog->head.magic = COREWAR_EXEC_MAGIC;
	prog->head.name_len = 0;
	ft_bzero(prog->head.name, PROG_NAME_LENGTH + 1);
	prog->head.com_len = 0;
	ft_bzero(prog->head.comment, COMMENT_LENGTH + 1);
	prog->head.end = 0;
	prog->head.prog_size = 0;
	prog->line = 0;
	prog->i = 0;
	prog->cor_size = 0;
}

int					main(int ac, char **av)
{
	t_asm			prog;
	int				i;

	i = 1;
	if (ac < 2)
		return (usage());
	init_prog(&prog);
	while (av[i] != NULL)
	{
		conv_file(av[i], &prog);
		if (prog.err.code != NO_ERR)
			print_err(av[i], &prog);
		else
		{
			create_cor(av[i], &prog);
			if (prog.err.code == NO_ERR)
				ft_printf("Champion made with %s\n", av[i]);
			else
				print_err(av[i], &prog);
		}
		reset_prog(&prog);
		i++;
	}
	return (i);
}
