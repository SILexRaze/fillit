/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:28:43 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 04:05:14 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_dim(char *str, int i, int n, int x)
{
	char	**tab;
	int		j;

	if (!(tab = ft_strsplit(str, 10)))
		ft_error();
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j] != '\0')
			if (tab[i][j] == '#')
				x++;
		if (j != 4)
			ft_error();
		if (n % 4 == 0 && i != 0 && x == 4)
		{
			x = 0;
			n = 0;
		}
		else if (n % 4 == 0 && i != 0 && x != 4)
			ft_error();
		n++;
	}
	return (1);
}

int		ft_check_dim2(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
		{
			if (i != 19)
				ft_error();
			else
				i = -1;
		}
		else
			i++;
		str++;
	}
	return (0);
}
