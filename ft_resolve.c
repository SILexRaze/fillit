/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/20 08:57:59 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_tab_point(char **square, int square_size)
{
	int i;
	int j;

	i = 0;
	square[square_size] = NULL;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = 0;
		i++;
	}
}

int		ft_resolve_algo(t_tetri *stock_tetri, char **square)
{
	int i;
	int x;
	int y;
	
	i = 0;
	while (i < 10)
	{
		ft_putchar('[');
		ft_putnbr(stock_tetri->tab[0][i]);
		ft_putchar(']');
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	i = 0;
	while (i < 19)
	{
		ft_putchar('[');
		ft_putnbr(stock_tetri->tab[1][i]);
		ft_putchar(']');
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');

	x = 0;
	y = 0;

	(void)square;
	return (1);
}

void	ft_resolve(t_tetri *stock_tetri)
{
	int square_size;
	char **square;
	int	i;

	square_size = ft_count_min_square(stock_tetri);
	if (!(square = (char **)malloc(sizeof(char *) * (square_size + 1))))
		ft_error();
	square[square_size] = 0;
	i = 0;
	while (i < square_size)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * (square_size + 1))))
			ft_error();
		square[i][square_size] = 0;
		i++;
	}
	ft_set_tab_point(square, square_size);
	ft_putstr("\nsquare_size : ");
	ft_putnbr(square_size);
	ft_putstr("\n");
	while (!(ft_resolve_algo(stock_tetri, square)))
	{
		ft_print_square(square);
		square_size++;
		if (!(square = (char **)malloc(sizeof(char *) * (square_size + 1))))
			ft_error();
		square[square_size] = 0;
		i = 0;
		while (i < square_size)
		{
			if (!(square[i] = (char *)malloc(sizeof(char) * (square_size + 1))))
				ft_error();
			square[i][square_size] = 0;
			i++;
		}
		ft_set_tab_point(square, square_size);
	}
//		ft_print_square(square);
}
