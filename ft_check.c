/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/21 10:08:23 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char *str, int nb_tetri, int nb_line)
{
	if (nb_tetri > 26)
		ft_error();
	if (*str == '\n' && *(str + 1) == '\n' && nb_line == 4)
		return (1);
	if (*str == '\n' && nb_line > 4)
		ft_error();
	else if (*str == '\n')
		return (2);
	else
		ft_error();
	return (0);
}

int		ft_check_input(char *str)
{
	int j;
	int ret;
	int	nb_line;
	int	nb_tetri;

	nb_tetri = 0;
	while (*(str + 1))
	{
		j = 0;
		nb_line = 0;
		while (*str++ && (*str == '.' || *str == '#'))
			j++;
		if (j > 4)
			ft_error();
		else
		{
			ret = ft_check_line(str, nb_tetri, nb_line);
			if (ret == 1 && *str++)
				nb_tetri++;
			else if (ret == 2)
				nb_line++;
		}
		str++;
	}
	return (1);
}
