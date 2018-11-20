/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:28:09 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/20 18:21:51 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_put_tetri_in_sq(char **square, int x, int y, int index)
{
	int static		i;

	if (square[y][x] && square[y][x] == '.')
	{
		square[y][x] = i + 'A';
		i++;
	return (1);
	}
	return (0);
	(void)index;
}

int		ft_del_tetri_in_sq(char **square, char c)
{
	int	i;
	int	j;

	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			if (square[i][j] == c)
				square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}
