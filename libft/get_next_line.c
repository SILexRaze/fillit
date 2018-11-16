/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:07:41 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/15 16:11:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*char	*ft_strdjoin(char *s1, char *s2)
{
	char	*str;

	if (s2)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}
*/
char	*ft_parse_tmp(char *save, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(save, 10)))
	{
		*tmp = 0;
		if (!(tmp = ft_strdup(tmp + 1)))
			return (NULL);
		if (!(*line = ft_strdup(save)))
			return (NULL);
		ft_strdel(&save);
		save = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(save)))
			return (NULL);
		ft_strclr(save);
	}
	return (save);
}

int		ft_strrdel(int ret, char *save)
{
	ft_strdel(&save);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!save && !(save = (char*)malloc(0)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		buf[ret] = '\0';
		if (!(save = ft_strdjoin(save, buf)))
			return (-1);
		if (ft_strchr(buf, 10))
			break ;
	}
	if (ret <= 0 && !(*save))
		return (ret);
	if (!(save = ft_parse_tmp(save, line)))
		return (ft_strrdel(ret, save));
	return (1);
}
