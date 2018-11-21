/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:28:09 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/21 12:46:44 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_put_tetri_in_sq(char **square, int x, int y, int index)
{
	char		**base;
	int			col;
	int			i;
	static int	n;

	base = ft_init_tetri_base();
	i = 0;
	col = 0;
	while (base[index][i])
	{
		if (index == 8)
		{
			if (col > 1)
			{
				col = 0;
				x -= 2;
				y++;
			}
		}
		else if (index == 11 || index == 13 || index == 18)
		{
			if (col > 2)
			{
				col = 0;
				x -= 3;
				y++;
			}
		}
		else if (index == 4 || index == 16)
		{
			if (col > 2)
			{
				col = 0;
				x -= 4;
				y++;
			}
		}
		else
		{
			if (col > 3)
			{
				col = 0;
				x -= 4;
				y++;
			}
		}
		if (square[y][x] == '.' && base[index][i] == '#')
			square[y][x] = n + 'A';
		else if (square[y][x] != '.' && base[index][i] == '#')
		{
			ft_del_tetri_in_sq(square, n + 'A');
			return (0);
		}
		x++;
		i++;
		col++;
	}
	if (base[index][i] != '\0')
		return (0);
	n++;
	return (1);
}

int		ft_del_tetri_in_sq(char **square, char c)
{
	int	i;
	int	j;

	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			if (square[i][j] == c)
				square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}
