/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:40:53 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/20 19:25:22 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0 && ft_islower(str[i]))
			str[i] -= 32;
		else if (ft_islower(str[i]) && (!ft_isalnum(str[i - 1])
				&& ft_isprint(str[i])))
			str[i] -= 32;
		i++;
	}
	return (str);
}
