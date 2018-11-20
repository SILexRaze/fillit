/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:41:41 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/20 08:13:25 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
#include <fcntl.h>


typedef struct	s_tetri
{
	int			tab[2][19];
}				t_tetri;

void			ft_print_square(char **square);

void			ft_resolve(t_tetri *stock_tetri);
void			ft_set_tab_point(char **square, int square_size);

int				ft_count_min_square(t_tetri *stock_tetri);
int				ft_count_min_square_y_min(t_tetri *stock_tetri);

t_tetri			*ft_parsing(int ac, char **av);
char			*ft_read_file(char *filename);
char			*ft_swap_nl_to_x(char *str);
void			ft_cut_to_tetri(char **tetri);
char			*ft_set_in_one_line(char *str);

void			ft_set_stock_to_zero(t_tetri *stock_tetri);

void			ft_error(void);

char			**ft_init_tetri_base(void);

int				ft_ischar(char c);
int				ft_check_char(char *str);
int				ft_check_input(char *str);
#endif
