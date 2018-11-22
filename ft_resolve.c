/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/22 21:50:41 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		ft_count_tetri(t_tetri *stock_tetri)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		count += stock_tetri->tab[1][i];
		i++;
	}
	return (count);
}

void	ft_set_square(t_tetri *stock_t, int sizeplus)
{
	int	edge;
	int i;

	edge = ft_calc_edge(stock_t, sizeplus);

	if (!(stock_t->square = (char **)malloc(sizeof(char *) * (edge + 1))))
		ft_error();
	stock_t->square[edge] = 0;
	i = 0;
	while (i < edge)
	{
		if (!(stock_t->square[i] = (char *)malloc(sizeof(char) * (edge + 1))))
			ft_error();
		stock_t->square[i][edge] = 0;
		i++;
	}
	stock_t->square = ft_set_tab_point(stock_t->square, edge);
}

int		ft_backtrack(t_tetri *stock_t, int pcs, int edge)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if(pcs == ft_count_tetri(stock_t))
		return (1);
	while (y < edge)
	{
		x = 0;
		while (x < edge)
		{
			if (ft_put_tetri_in_sq(stock_t->square, x, y, stock_t->tab[0][pcs], edge, pcs))
			{
				if (ft_backtrack(stock_t, pcs + 1, edge))
					return (1);
			}
			ft_del_tetri_in_sq(stock_t->square, pcs +'A');
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_calc_edge(t_tetri *stock_tetri, int sizeplus)
{
	int i;
	int edge;

	edge = 0;
	i = 0;
	while (i < 19)
	{
		edge = edge + 4 * stock_tetri->tab[1][i];
		i++;
	}
	edge = ft_sqrt(edge) + sizeplus;
	return (edge);
}

void	ft_resolve(t_tetri *stock_t)
{
	int		sizeplus;

	sizeplus = 0;
	ft_set_square(stock_t, sizeplus);
	while (!(ft_backtrack(stock_t, 0, ft_calc_edge(stock_t, sizeplus))))
	{
		sizeplus++;
		ft_sqdel(&(stock_t->square));
		ft_set_square(stock_t, sizeplus);
	}
	ft_print_square(stock_t->square);
	ft_sqdel(&(stock_t->square));
}
