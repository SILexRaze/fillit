/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/22 11:47:45 by mabouce          ###   ########.fr       */
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

char	**ft_set_square(t_tetri *stock_tetri, int sizeplus)
{
	char **square;
	int	edge;
	int i;

	edge = ft_calc_edge(stock_tetri, sizeplus);

	if (!(square = (char **)malloc(sizeof(char *) * (edge + 1))))
		ft_error();
	square[edge] = 0;
	i = 0;
	while (i < edge)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * (edge + 1))))
			ft_error();
		square[i][edge] = 0;
		i++;
	}
	ft_set_tab_point(square, edge);
	return (square);
}

int		ft_backtrack(char **square, t_tetri *stock_tetri, 
		int x, int y, int pcs, int edge)
{

	if(pcs == ft_count_tetri(stock_tetri))
		return (1);
	while (y < edge)
	{
		x = 0;
		while (x < edge)
		{
			if (ft_put_tetri_in_sq(square, x, y, stock_tetri->tab[0][pcs], edge, pcs))
			{
				if (ft_backtrack(square, stock_tetri, 0, 0, pcs + 1, edge))
					return (1);
			}
			ft_del_tetri_in_sq(square, pcs +'A');
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

void	ft_resolve(t_tetri *stock_tetri)
{
	char **square;
	int		sizeplus;

	sizeplus = 0;
	square = ft_set_square(stock_tetri, sizeplus);
	while (!(ft_backtrack(square, stock_tetri, 0, 0, 0, ft_calc_edge(stock_tetri, sizeplus))))
	{
		sizeplus++;
		ft_sqdel(square);
		square = ft_set_square(stock_tetri, sizeplus);
	}
	ft_print_square(square);
	ft_sqdel(square);
}
