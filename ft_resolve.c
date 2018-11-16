/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/16 11:17:22 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_tab_point(int **square, int square_size)
{
	int i;
	int j;

	i = 0;
	square[square_size] = NULL;
	while (square[i])
	{
		j = 0;
		while (square[i][j] < square_size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = 0;
		i++;
	}
}

void	ft_resolve(t_tetri *stock_tetri)
{
	int square_size;
	int **square;
	int	i;

	square_size = ft_count_min_square(stock_tetri);
	if (!(square = (int **)malloc(sizeof(int *) * (square_size + 1))))
		ft_error();
	i = 0;
	while (square[i])
	{
		if (!(square[i] = (int *)malloc(sizeof(int) * (square_size + 1))))
			ft_error();
		i++;
	}
	//ft_set_tab_point(square, square_size);
	//ft_print_square(square);
	//	
	ft_putstr("square_size :\n");
	ft_putnbr(square_size);
	ft_putstr("\n");
	//
//	while (!ft_resolve_algo(stock_tetri, buf))
//	{
//		
//	}
}
