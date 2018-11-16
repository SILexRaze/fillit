/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:40:35 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/16 09:15:00 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"








#include <stdio.h>

char	*ft_read_file(char *filename)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;
	char	*tetri;

	i = 1;
	if (!(tetri = ft_strnew(0)))
		ft_error();
	if (!(fd = open(filename, O_RDONLY)))
		ft_error();
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0 || i > 129)
			ft_error();
			if (!(tetri = ft_strdjoin(tetri, ft_strdjoin(line, "\n"))))
			ft_error();
		i++;
	}
	return (ft_swap_nl_to_x(tetri));
}

char	*ft_swap_nl_to_x(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			str[i + 1] = 'x';
		i++;
	}
	return (str);
}
// A FAIRE -> vifonne
/*void	ft_input_check(char *tetri)
{
	
}*/

void	ft_cut_to_tetri(char **tetri)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	while (tetri[i])
	{
		//ajouter free dup
		if (!(tetri[i] = ft_strdup(ft_strchr(tetri[i], '#'))))
			ft_error();
		j = 0;
		y = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				y++;
			if (y == 4)
			{
				tetri[i][j + 1] = '\0';
				break;
			}
			j++;
		}
		i++;
	}
}

char	*ft_set_in_one_line(char *str)
{
	char	**tab;
	char	*s1;

	s1 = ft_strnew(0);
	tab = ft_strsplit(str, '\n');
	while (*tab)
		s1 = ft_strdjoin(s1, *tab++);
	return (s1);
}

void	ft_parsing(int ac, char **av)
{
	char	**tetri;
	char	**tetri_base;
	t_tetri	*stock_tetri;	
	int		match;
	int		i;
	int		j;

	if (!(stock_tetri = malloc(sizeof(t_tetri))))
		ft_error();
	ft_set_stock_to_zero(stock_tetri);
	if (ac != 2)
		ft_error();
//	ft_input_check(tetri);
	tetri = ft_strsplit(ft_set_in_one_line(ft_read_file(av[1])), 'x');
	ft_cut_to_tetri(tetri);
	tetri_base = ft_init_tetri_base();
	i = 0;
	while (tetri[i])
	{
		match = 0;
		j = 0;
		while (tetri_base[j])
		{
			if (ft_strequ(tetri[i], tetri_base[j]))
			{
				match = 1;
				stock_tetri->i[j]++;
				break ;
			}
			j++;
		}
		if (match != 1)
		{
			ft_error();
		}
		i++;
	}
	match = -1;
	while (++match < 19)
	{
		ft_putnbr(stock_tetri->i[match]);
		ft_putchar('\n');
	}
}
