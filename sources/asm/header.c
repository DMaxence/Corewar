/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/26 16:53:58 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static t_ernum				get_comment(char *line, t_asm *prog)
{
	int						i;

	i = 0;
	while (line[i] && line[i] != '"')
	{
		prog->head.comment[prog->head.com_len] = line[i];
		prog->head.com_len++;
		i++;
	}
	if (!line[i])
	{
		prog->head.comment[prog->head.com_len] = 10;
		prog->head.com_len++;
		return (NO_ERR);
	}
	i += 1 + ft_count_white(line + i + 1);
	if (line[i] && line[i] != COMMENT_CHAR)
		return (HEAD_ERR);
	prog->head.end += 2;
	return (NO_ERR);
}

static t_ernum				get_name(char *line, t_asm *prog)
{
	int						i;

	i = 0;
	while (line[i] && line[i] != '"')
	{
		prog->head.name[prog->head.name_len] = line[i];
		prog->head.name_len++;
		i++;
	}
	if (!line[i])
	{
		prog->head.name[prog->head.name_len] = 10;
		prog->head.name_len++;
		return (NO_ERR);
	}
	i += 1 + ft_count_white(line + i + 1);
	if (line[i] && line[i] != COMMENT_CHAR)
		return (HEAD_ERR);
	prog->head.end += 1;
	return (NO_ERR);
}

static void					loop_head_line(char *line, int i, int swap,
							t_asm *prog)
{
	int						ret;

	ret = 1;
	while (ret > 0 && prog->head.end < swap)
	{
		if (swap == 1 || (swap == 3 && prog->head.end == 2))
			prog->err.code = get_name(line + i, prog);
		else if (swap == 2 || (swap == 3 && prog->head.end == 1))
			prog->err.code = get_comment(line + i, prog);
		else if (prog->head.end == swap)
		{
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
		if (prog->err.code == NO_ERR && prog->head.end < swap)
			ret = get_next_line(prog->fd, &line);
		else
			return ;
		i = 0;
	}
	if (ret <= 0)
		prog->err.code = HEAD_ERR;
}

void						fill_header(char *line, int i, t_asm *prog)
{
	int						swap;

	swap = 0;
	if (ft_strncmp(line + i, NAME_CMD_STRING,
	ft_strlen(NAME_CMD_STRING)) == 0)
	{
		swap = 1;
		i += ft_strlen(NAME_CMD_STRING);
	}
	else if (ft_strncmp(line + i, COM_CMD_STRING,
	ft_strlen(COM_CMD_STRING)) == 0)
	{
		swap = 2;
		i += ft_strlen(COM_CMD_STRING);
	}
	i += ft_count_white(line + i);
	if ((line[i] || line[i] != '"'))
		prog->err.code = HEAD_ERR;
	else
		loop_head_line(line, i + 1, swap + prog->head.end, prog);
	return ;
}
