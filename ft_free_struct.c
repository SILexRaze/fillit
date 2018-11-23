/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:08:14 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/23 13:19:26 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_struct(t_tetri *stock_t)
{
	if (stock_t)
	{
		if ((stock_t)->tetri)
			ft_strdel(&(stock_t)->tetri);
		free(stock_t);
	}
}
