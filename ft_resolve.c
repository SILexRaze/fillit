/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/21 12:01:29 by vifonne          ###   ########.fr       */
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

	i = 0;
	edge = 0;
	while (i < 19)
	{
		edge = edge + 4 * stock_tetri->tab[1][i];
		i++;
	}
	edge = ft_sqrt(edge) + sizeplus;

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

int		ft_backtrack(char **square, t_tetri *stock_tetri, int x, int y, int pcs)
{

	if (pcs == ft_count_tetri(stock_tetri))
		return (1);
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{

			// VERIF SI TU PEUX POSER LA PIECE ON LA POSE, SI TU PEUX TU LA POSER -> RECURSIVITE
			// SI TU PEUX, TU RAPPELLES LA FONCTION BACKTRACK --> IF (BACKTRACK == 1) RETURN 1
			// SI CA RETOURNE PAS HEEEIN, ENLEVER LA PIECE ET ESSAYER UNE AUTRE COMBINAISON
			/*
			 *	if (is_valid x y)
			 *		put shape
			 *		if (backtrack autre piece)
			 *			return 1
			 *		else
			 *			rm_shape;
			 *		changement de position (LEULEU)
			 *
			 *
			 *
			 */
			if (ft_put_tetri_in_sq(square, x, y, stock_tetri->tab[0][pcs]))
				if (ft_backtrack(square, stock_tetri, 0, 0, pcs + 1))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_resolve(t_tetri *stock_tetri)
{
	char **square;
	int		sizeplus;

	sizeplus = 0;
	square = ft_set_square(stock_tetri, sizeplus);
	while (!(ft_backtrack(square, stock_tetri, 0, 0, 0)))
	{
		sizeplus++;
		square = ft_set_square(stock_tetri, sizeplus);
	}
	ft_print_square(square);
	ft_putchar('\n');
}
