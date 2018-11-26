/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/22 15:34:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static int	ft_magic_number(int fd, t_header *header)
{
	unsigned int	magic_number;

	if (read(fd, &magic_number, sizeof(COREWAR_EXEC_MAGIC))
			!= sizeof(COREWAR_EXEC_MAGIC))
		return (ft_msgfdret("read error\n", 2, 0));
	ft_memrev(&magic_number, 4);
	if (magic_number != COREWAR_EXEC_MAGIC)
		return (ft_msgfdret("wrong magic number\n", 2, 0));
	header->magic = magic_number;
	return (1);
}

static int	ft_champ_injection(int fd, t_stock *s, t_champ *champ)
{
	char	buf[CHAMP_MAX_SIZE];
	int		index_injection;

	if (read(fd, &buf, champ->header->prog_size) < champ->header->prog_size)
		return (ft_msgfdret("too big program\n", 2, 0));
	index_injection = (MEM_SIZE / s->nb_player) * (champ->nb_player - 1);
	ft_memcpy(&s->memory[index_injection], buf, champ->header->prog_size);
	return (ft_new_process(index_injection, champ->nb_player, s));
}

static int	ft_new_player_second(int fd, t_stock *s, t_champ *champ)
{
	char	buf[4];

	if (!(ft_magic_number(fd, champ->header)))
		return (0);
	if ((read(fd, &champ->header->prog_name, PROG_NAME_LENGTH)
				< PROG_NAME_LENGTH)
			|| ((read(fd, &buf, 4)) < 4)
			|| (buf[0] || buf[1] || buf[2] || buf[3])
			|| ((read(fd, &champ->header->prog_size, 4)) < 4)
			|| (read(fd, &champ->header->comment, COMMENT_LENGTH)
				< COMMENT_LENGTH)
			|| ((read(fd, &buf, 4)) < 4)
			|| (buf[0] || buf[1] || buf[2] || buf[3]))
		return (ft_msgfdret("read error\n", 2, 0));
	champ->header->prog_name[PROG_NAME_LENGTH] = '\0';
	if (s->opt_v && ft_strchr(champ->header->prog_name, '\n'))
		*ft_strchr(champ->header->prog_name, '\n') = '\0';
	champ->header->comment[COMMENT_LENGTH] = '\0';
	ft_memrev(&champ->header->prog_size, 4);
	if ((int)champ->header->prog_size > CHAMP_MAX_SIZE)
		return (ft_msgfdret("too big program\n", 2, 0));
	return (ft_champ_injection(fd, s, champ));
}

int			ft_new_player(char *str, t_stock *s)
{
	int	nb_p;
	int	fd;

	nb_p = -1;
	while (s->champ[++nb_p]->nb_player)
		;
	s->champ[nb_p]->nb_player = nb_p + 1;
	if ((fd = open(str, O_RDONLY)) < 1)
	{
		ft_putstr_fd("open error : ", 2);
		ft_putendl_fd(str, 2);
		return (0);
	}
	if (!ft_new_player_second(fd, s, s->champ[nb_p]))
		return (0);
	close(fd);
	return (1);
}
