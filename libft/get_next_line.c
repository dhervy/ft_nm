/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:43 by dhervy            #+#    #+#             */
/*   Updated: 2016/02/09 22:01:57 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_returnstr(char *str)
{
	int		i;
	char	*s;
	char	*l;

	i = 0;
	while (str[i] != DELIMITE)
		i++;
	s = &str[i + 1];
	l = str;
	str = ft_strdup(s);
	free(l);
	return (str);
}

static char	**ft_returnline(char **line, char *str)
{
	int		i;

	i = 0;
	while (str[i] != DELIMITE)
		i++;
	*line = ft_strndup(str, i);
	return (line);
}

static char	*ft_buftostr(char *str, char *buf, int ret)
{
	if (!str)
		str = ft_strdup(buf);
	else if (ret != 0 && str && ft_strchr(str, DELIMITE) == 0)
		str = ft_strjoinfree(str, buf, 0);
	return (str);
}

static int	ft_return(char **str, int fd, int ret, char **line)
{
	if (ret == 0 && *str[fd] == '\0')
		return (0);
	else if (ret == 0 && ft_strchr(str[fd], DELIMITE) == 0)
	{
		*line = ft_strdup(str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*str[256];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	ret = 1;
	while (ret != 0)
	{
		if (!str[fd] || ft_strchr(str[fd], DELIMITE) == 0)
		{
			ret = read(fd, buf, BUFF_SIZE);
			buf[ret] = '\0';
		}
		if (ret == 0)
			return (ft_return(str, fd, ret, line));
		str[fd] = ft_buftostr(str[fd], buf, ret);
		if ((ft_strchr(str[fd], DELIMITE)) != 0)
		{
			line = ft_returnline(line, str[fd]);
			str[fd] = ft_returnstr(str[fd]);
			return (1);
		}
	}
	return (0);
}
