/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:21:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/21 22:10:06 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri	*stock_tetri;

	if (!(stock_tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		ft_error();
	if (ac != 2)
		ft_error();
	stock_tetri = ft_parsing(av, stock_tetri);
	ft_resolve(stock_tetri);
	return (0);
}
