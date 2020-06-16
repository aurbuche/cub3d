/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:13:54 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/16 13:00:25 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int				ft_store_map(char *line, t_cub *cub)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = -1;
	cub->map = (char **)malloc(sizeof(char *) * cub->n_line);
	while (line[i])
	{
		k = 0;
		j++;
		cub->map[j] = (char *)malloc(sizeof(char) * ft_cchr(line, i, '~') - i);
		while (line[i] && line[i] != '~')
		{
			cub->map[j][k] = line[i];
			k++;
			i++;
		}
		if (i == ft_strlen(line))
			break ;
		i++;
	}
	return (1);
}

int				ft_temporary(char *line, t_cub *cub)
{
	char	*tmp;

	tmp = ft_strdup("");
	while (get_next_line(cub->fd, &line) > 0)
	{
		if (cub->n_line == 0 && line[0] != '\0')
		{
			tmp = ft_strdup(line);
			cub->n_line++;
		}
		else if (cub->n_line != 0)
		{
			tmp = ft_strfjoin(tmp, "~", 1);
			tmp = ft_strfjoin(tmp, line, 1);
			cub->n_line++;
		}
	}
	tmp = ft_strfjoin(tmp, "~", 1);
	if (ft_store_map(tmp, cub))
		ft_disp_ok("MAP CHECKED IN");
	return (1);
}

int	           ft_map_analyze(char *line, t_cub *cub)
{
    if (!ft_temporary(line, cub))
		return (0);
	return (1);
}
