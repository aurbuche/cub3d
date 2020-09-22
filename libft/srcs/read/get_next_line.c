/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:22:31 by aurbuche          #+#    #+#             */
/*   Updated: 2020/09/22 14:26:47 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#include "../../include/get_next_line.h"

static int				ft_gnl_check_error(int fd, char **str)
{
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		if (*str)
			free(*str);
		return (-1);
	}
	if (*str == NULL)
	{
		if (!(*str = ft_strdup("")))
		{
			free(*str);
			return (-1);
		}
	}
	return (0);
}

static char		*ft_read(char *str, int fd)
{
	char	*buff;
	char	*tmp;
	int		ret;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str, buff);
		str = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

static int				ft_complete(char **str, char **line)
{
	size_t i;
	char *tmp;

	i = 0;
	while (*str && *str[i])
	{
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		if ((*str)[i] == '\n')
		{
			*line = ft_substr(*str, 0, i);
			tmp = ft_strdup((*str) + i + 1);
			free(*str);
			*str = tmp;
			return (1);
		}
		else
		{
			*line = ft_substr(*str, 0, i);
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}

size_t				get_next_line(int fd, char **line)
{
	static char		*str = NULL;

	*line = NULL;
	if (ft_gnl_check_error(fd, &str) == -1)
		return (-1);
	str = ft_read(str, fd);
	if (ft_complete(&str, line) == 0)
	{
		free(str);
		return (0);
	}
	return (1);
}
