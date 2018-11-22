/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/22 13:23:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int		ft_check_line(char *str, int nb_tetri, int nb_line)
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

  int		ft_check_input(char *str)
  {
  int j;
  int ret;
  int	nb_line;
  int	nb_tetri;
  int	i;

  i = 0;
  nb_tetri = 0;
  while (str[i + 1])
  {
  j = 0;
  nb_line = 0;
  while (str[i++] && (str[i] == '.' || str[i] == '#'))
  j++;
  if (j > 4)
  ft_error();
  else
  {
  ret = ft_check_line(str, nb_tetri, nb_line);
  if (ret == 1 && str[i++])
  nb_tetri++;
  else if (ret == 2)
  nb_line++;
  }
  i++;
  }
  return (1);
  }*/

int		ft_check_input(char *str)
{
	int i;
	int	x;
	int	nl;
	int nbtetri;

	nbtetri = 0;
	i = 0;
	nl = 0;
	while (str[i])
	{
		x = 0;
		while (str[i] != '\n')
		{
			if (str[0] != '.' && str[0] != '#')
				ft_error();
			if (x > 3)
			{
				printf("ici\n");
				ft_error();
			}
			x++;
			i++;
		}
		if (x < 3)
				ft_error();
		if(str[i] == '\n')
		i++;
	}
	return (1);
}

/*int		ft_check_input(char *str)
  {
  int currentx;
  int	currenty;
  int i;
  int nb_tetri;

  currentx = 0;
  currenty = 0;
  i = 0;
  nb_tetri = 0;
  ft_check_ln(str);
  }*/
