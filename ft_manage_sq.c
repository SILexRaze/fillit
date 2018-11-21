/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:28:09 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/21 10:58:31 by vifonne          ###   ########.fr       */
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
		if (col >= 4)
		{
			col = 0;
			x -= 4;
			y++;
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
