/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:21:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/16 17:50:11 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri	*stock_tetri;
//	int		i;

	stock_tetri = ft_parsing(ac, av);


/*	//affichage des matchs
	i = -1;
	while (++i < 19)
	{
		ft_putnbr(stock_tetri->tab[i]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	//a remove
	ft_resolve(stock_tetri);*/
	return (0);
}
