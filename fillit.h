/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:41:41 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/16 09:21:03 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
#include <fcntl.h>


typedef struct		s_tetri
{
	int				i[19];
}					t_tetri;

t_tetri				*ft_parsing(int ac, char **av);
char				*ft_read_file(char *filename);
char				*ft_swap_nl_to_x(char *str);
void				ft_cut_to_tetri(char **tetri);
char				*ft_set_in_one_line(char *str);

void				ft_set_stock_to_zero(t_tetri *stock_tetri);

void				ft_error(void);

char				**ft_init_tetri_base(void);

#endif
