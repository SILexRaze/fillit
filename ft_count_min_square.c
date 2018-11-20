/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_min_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:49:40 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/20 14:41:50 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_min_square_y_min(t_tetri *stock_tetri)
{
	int y_min;

	y_min = 0;
	y_min += stock_tetri->tab[1][2] * 2 + stock_tetri->tab[1][3] * 2
		+ stock_tetri->tab[1][5] * 2 + stock_tetri->tab[1][7] * 2
		+ stock_tetri->tab[1][8] * 2 + stock_tetri->tab[1][11] * 2
		+ stock_tetri->tab[1][13] * 2 + stock_tetri->tab[1][15] * 2
		+ stock_tetri->tab[1][17] * 2;
	y_min += stock_tetri->tab[1][4] * 3 + stock_tetri->tab[1][6] * 3
		+ stock_tetri->tab[1][9] * 3 + stock_tetri->tab[1][10] * 3
		+ stock_tetri->tab[1][12] * 3 + stock_tetri->tab[1][14] * 3
		+ stock_tetri->tab[1][16] * 3 + stock_tetri->tab[1][18] * 3;
	y_min += stock_tetri->tab[1][0] * 1;
	y_min += stock_tetri->tab[1][1] * 4;
	return (1);
}

int		ft_count_min_square(t_tetri *stock_tetri)
{
	int	x_min;
	int	y_min;

	x_min = 0;
	x_min += stock_tetri->tab[1][2] * 2 + stock_tetri->tab[1][4] * 2
		+ stock_tetri->tab[1][6] * 2 + stock_tetri->tab[1][9] * 2
		+ stock_tetri->tab[1][10] * 2 + stock_tetri->tab[1][12] * 2
		+ stock_tetri->tab[1][14] * 2 + stock_tetri->tab[1][16] * 2
		+ stock_tetri->tab[1][18] * 2;
	x_min += stock_tetri->tab[1][3] * 3 + stock_tetri->tab[1][5] * 3
		+ stock_tetri->tab[1][7] * 3 + stock_tetri->tab[1][8] * 3
		+ stock_tetri->tab[1][13] * 3 + stock_tetri->tab[1][15] * 3
		+ stock_tetri->tab[1][11] * 3 + stock_tetri->tab[1][17];
	x_min += stock_tetri->tab[1][0] * 4;
	x_min += stock_tetri->tab[1][1] * 1;
	y_min = ft_count_min_square_y_min(stock_tetri);
	return (1);
}
