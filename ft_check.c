/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/22 14:30:59 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_line(char *str, int nb_tetri, int nb_line)
{
	if (nb_tetri > 26)
		ft_error();
	if (*str == '\n' && *(str + 1) == '\n' && nb_line == 4)
		return (1);
	if (*str == '\n' && nb_line > 4)
		ft_error();
	else if (*str == '\n')
		return (2);
	return (0);
}

int		ft_ischar(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

int		ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_ischar(str[i]) && str[i] != '\n')
			ft_error();
		i++;
	}
	return (1);
}

int ft_check_input(char *str)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	ft_check_char(str);
	while (*str)
	{
		if (*str == '\n' && ft_ischar(*(str + 1)) == 1)
		{
			if (col >= 4)
				col = 0;
			else
			{
				ft_putchar('t');
				ft_error();
			}
			line++;
		}
		else if (*str == '\n' && *(str + 1) == '\n')
		{
			if (line >= 4)
				line = 0;
			else
			{
				printf("%d\n", line);
				ft_putchar('e');
				ft_error();
			}
		}
		col++;
		str++;
	}
	return (1);
}
