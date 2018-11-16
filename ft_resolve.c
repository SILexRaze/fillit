/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:27:27 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/16 10:50:48 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_resolve(t_tetri *stock_tetri)
{
	int square_size;

	square_size = ft_count_min_square(stock_tetri);

	//	
	ft_putstr("square_size :\n");
	ft_putnbr(square_size);
	ft_putstr("\n");
	//

	//	while (ft_resolve_algo(stock_tetri, buf))
	//	{
	//		
	//	}
}
