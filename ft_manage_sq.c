/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:28:09 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 03:57:27 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_put_tetri_in_sq(char **square, int x, int y, int index, int edge, int pcs)
{
	char		**base;
	int			i;

	i = 0;
	if (!(base = ft_init_tetri_base_for_put()))
		ft_error();
	while (base[index][i] && y < edge && x >= 0)
	{
		if (base[index][i] == '#' && square[y][x] == '.')
		{
			square[y][x] = pcs + 'A';
			x++;
		}
		else if (base[index][i] == '#' && square[y][x] != '.')
		{
			return (0);
		}
		else if (base[index][i] == '-')
		{
			if (x - 1 < 0)
			{
				return (0);
			}
			x--;
		}
		else if (base[index][i] == '+' && y + 1 < edge)
			y++;
		i++;
	}
	free(base);
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

void	ft_sqdel(char ***square)
{
	int	i;

	i = 0;
	if (*square)
	{
		while ((*square)[i])
		{
			ft_strdel((*square) + i);
			i++;
		}
		free(*square);
		*square = NULL;
	}
}
