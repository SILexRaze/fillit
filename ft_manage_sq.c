/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:28:09 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/23 11:11:09 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_put_tetri_in_sq(t_tetri *stock_t,
		int x, int y, int pcs)
{
	char		**base;
	int			i;

	i = 0;
	if (!(base = ft_init_tetri_base_for_put()))
		ft_error();
	while (base[stock_t->tab[0][pcs]][i] && y < stock_t->edge && x >= 0)
	{
		if (base[stock_t->tab[0][pcs]][i] == '#'
				&& stock_t->square[y][x] == '.')
			stock_t->square[y][x++] = pcs + 'A';
		else if (base[stock_t->tab[0][pcs]][i] == '#'
				&& stock_t->square[y][x] != '.')
			return (0);
		else if (base[stock_t->tab[0][pcs]][i] == '-')
		{
			if (x-- - 1 < 0)
				return (0);
		}
		else if (base[stock_t->tab[0][pcs]][i] == '+' && y + 1 < stock_t->edge)
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
