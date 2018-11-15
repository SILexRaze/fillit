/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:40:35 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/15 14:32:08 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
char	**ft_init_db(void)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 20)))
		return (0);
	tab[0] = "####";
	tab[1] = "#OOO#OOO#OOO#";
	tab[2] = "##OO##";
	tab[3] = "###OOO#";
	tab[4] = "#OOO#OO##";
	tab[5] = "#OOO###";
	tab[6] = "##OO#OOO#";
	tab[7] = "###O#";
	tab[8] = "#O###";
	tab[9] = "#OOO#OOO##";
	tab[10] = "##OOO#OOO#";
	tab[11] = "##O##";
	tab[12] = "#OOO##OOO#";
	tab[13] = "#OO###";
	tab[14] = "#OOO##OO#";
	tab[15] = "###OO#";
	tab[16] = "#OO##OOO#";
	tab[17] = "##OOO##";
	tab[18] = "#OO##OO#";
	tab[19] = NULL;
	return (tab);
}
