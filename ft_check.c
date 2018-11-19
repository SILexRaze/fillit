/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/19 14:52:42 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_ischar(char c)
{
	if (c == '.' || c == '#' || c == '\n')
		return (1);
	return (0);
}

int		ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_ischar(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_input(char *str)
{
	int	i;
	int j;
	int	nb_line;

	i = 0;
	nb_line = 0;
	if (!ft_check_char(str))
		ft_error();
	while (str[i + 1])
	{
		j = 0;
		while (str[i + 1] && (str[i] == '.' || str[i] == '#'))
		{
			j++;
			i++;
		}
		if (j > 4)
			ft_error();
		else
		{
			if (str[i] == '\n' && str[i + 1] == '\n');
				nb_line++;
			else
				ft_error();
		}
		i++;
	}
	return (1);
}
