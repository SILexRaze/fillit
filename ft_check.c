/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/16 18:21:26 by vifonne          ###   ########.fr       */
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
	j = 1;
	nb_line = 0;
	if (!ft_check_char(str))
		ft_error();
	while (str[i])
	{
		if (str[i] == '\n')
			nb_line++;
		j++;
		i++;
	}
	return (1);
}
