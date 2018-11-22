/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:40:35 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/22 12:11:46 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_file(char *filename)
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
	close(fd);
	if (!ft_check_input(tetri))
		ft_error();
	return (ft_swap_nl_to_x(tetri));
}

char		*ft_swap_nl_to_x(char *str)
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

void		ft_cut_to_tetri(char **tetri)
{
	int		i;
	int		j;
	int		y;
	char	*tmp;

	i = 0;
	while (tetri[i])
	{
		tmp = tetri[i];
		if (!(tetri[i] = ft_strdup(ft_strchr(tetri[i], '#'))))
			ft_error();
		ft_strdel(&tmp);
		j = 0;
		y = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				y++;
			if (y == 4)
			{
				tetri[i][j + 1] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}

char		*ft_set_in_one_line(char *str)
{
	char	**tab;
	char	*s1;

	s1 = ft_strnew(0);
	tab = ft_strsplit(str, '\n');
	while (*tab)
		s1 = ft_strdjoin(s1, *tab++);
	ft_sqdel(tab);
	return (s1);
}

t_tetri		*ft_parsing(char **av, t_tetri *stock_tetri)
{
	char	**tetri;
	char	**tetri_base;
	int		match;
	int		j;
	int		set_order;

	if (!(stock_tetri = malloc(sizeof(t_tetri))))
		ft_error();
	ft_set_stock_to_zero(stock_tetri);
	tetri = ft_strsplit(ft_set_in_one_line(ft_read_file(av[1])), 'x');
	ft_cut_to_tetri(tetri);
	tetri_base = ft_init_tetri_base();
	set_order = 0;
	while (*tetri)
	{
		match = 0;
		j = 0;
		while (tetri_base[j])
		{
			if (ft_strequ(*tetri, tetri_base[j]))
			{
				match = 1;
				stock_tetri->tab[0][set_order] = j;
				stock_tetri->tab[1][j]++;
				set_order++;
				break ;
			}
			j++;
		}
		if (match != 1)
			ft_error();
		tetri++;
	}
	return(stock_tetri);
}
