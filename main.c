/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:21:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/22 21:48:21 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_main_parsing(char **av, t_tetri *stock_t)
{
	ft_set_stock_to_zero(stock_t);
	stock_t = ft_read_file(stock_t, av[1]);
	stock_t->tetri_block = ft_strsplit(ft_set_in_one_line(stock_t->tetri), 'x');
	ft_cut_to_tetri(stock_t->tetri_block);
	ft_parsing(stock_t, 0);
	return (stock_t);
}

int		main(int ac, char **av)
{
	t_tetri	*stock_t;

	if (ac != 2)
		ft_error();
	if (!(stock_t = (t_tetri *)malloc(sizeof(t_tetri))))
		ft_error();
	stock_t->t_base = ft_init_tetri_base();
	ft_resolve(ft_main_parsing(av, stock_t));
	return (0);
}
