/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/20 08:04:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_input(char *str)
{
	int	i;
	int j;
	int	nb_line;
	int	nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (str[i + 1])
	{
		j = 0;
		nb_line = 0;
		while (str[i] && (str[i] == '.' || str[i] == '#'))
		{
			j++;
			i++;
		}
		if (j > 4)
			ft_error();
		else
		{
			if (str[i] == '\n' && str[i + 1] == '\n' && nb_line == 4)
			{
				nb_tetri++;
				i++;
			}
			if (str[i] == '\n' && nb_line > 4)
				ft_error();
			else if (str[i] == '\n')
				nb_line++;
			else
				ft_error();
		}
		i++;
	}
	return (1);
}
