/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/19 21:22:46 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void			get_header(t_asm *prog)
{
	char			*line;
	int				ret;
	int				i;

	i = 0;
	ret = 0;
	if ((ret = get_next_line(prog->fd, &line)) <= 0)
		prog->err.code = ETY_FILE;
	while (ret > 0 && prog->err.code == NO_ERR)
	{
		i = ft_count_white(line);
		if (!line[i] || line[i] == COMMENT_CHAR)
			ft_strdel(&line);
		else
			fill_header(line, i, prog);
		if (prog->err.code == NO_ERR && prog->head.end != 3)
			ret = get_next_line(prog->fd, &line);
		else
		{
			if (prog->head.end != 3)
				ft_strdel(&line);
			break ;
		}
	}
}

static void			get_pro(t_asm *prog)
{
	char			*line;
	int				ret;
	int				i;

	ret = 0;
	if ((ret = get_next_line(prog->fd, &line)) <= 0)
	{
		prog->err.code = NO_PRO;
		return ;
	}
	while (ret > 0 && prog->err.code == NO_ERR)
	{
		i = ft_count_white(line);
		if (!line[i] || line[i] == COMMENT_CHAR)
			ft_strdel(&line);
		else
		{
			fill_pro(line + i, prog);
			ft_strdel(&line);
		}
		if (prog->err.code == NO_ERR)
			ret = get_next_line(prog->fd, &line);
		else
			return ;
	}
}

static void			fill_cor(t_asm *prog)
{
	int						i;

	i = 0;
	while (i < prog->line)
	{
		prog->head.prog_size += prog->byte[i].nb_oct;
		if (prog->head.prog_size > CHAMP_MAX_SIZE)
		{
			prog->err.code = PROG_SIZE;
			return ;
		}
		i++;
	}
	prog->cor_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16
		+ prog->head.prog_size;
	if (!(prog->cor = (char *)malloc(sizeof(char) * (prog->cor_size + 16))))
	{
		prog->err.code = MLC_ERR;
		return ;
	}
	ft_bzero(prog->cor, prog->cor_size);
	if (head_step(prog))
		return ;
	if (byte_step(prog))
		return ;
}

void				conv_file(char *file, t_asm *prog)
{
	if ((prog->fd = open(file, O_RDONLY)) < 0)
	{
		prog->err.code = ERR_OPEN;
		return ;
	}
	if (ft_strend(file, ".s") == 0)
	{
		prog->err.code = ERR_TYPE;
		return ;
	}
	get_header(prog);
	if (prog->err.code != NO_ERR)
		return ;
	get_pro(prog);
	if (prog->err.code != NO_ERR)
		return ;
	check_pro(prog);
	if (prog->err.code != NO_ERR)
		return ;
	translate(prog);
	if (prog->err.code != NO_ERR)
		return ;
	fill_cor(prog);
	if (close(prog->fd) < 0)
		prog->err.code = ERR_CLOSE;
}
