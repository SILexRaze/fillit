/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:05:26 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/20 14:21:23 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_square(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putendl(square[i]);
		i++;
	}
}
