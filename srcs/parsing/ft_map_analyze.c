/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:13:54 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 17:39:45 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int			ft_store_map(char *line, t_cub *cub, size_t i, size_t j)
{
	size_t	k;

	cub->map = malloc(sizeof(char *) * cub->n_line);
	while (line[i])
	{
		k = 0;
		j++;
		cub->map[j] = (char *)malloc(sizeof(char) *
		(ft_cchr(line, i, '~') - i + 1));
		while (line[i] && line[i] != '~')
		{
			if (ft_strchr("NSEW", line[i]))
				ft_start_player_pos(line[i], cub, k, j);
			cub->map[j][k] = line[i];
			k++;
			i++;
		}
		cub->map[j][k] = '\0';
		if (i == ft_strlen(line))
			break ;
		i++;
	}
	return (1);
}

int					ft_temporary(char *line, t_cub *cub)
{
	char	*tmp;

	tmp = NULL;
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
	if (!ft_store_map(tmp, cub, 0, -1))
		return (0);
	ft_delete(&tmp);
	ft_delete(&line);
	return (1);
}

int					ft_map_analyze(char *line, t_cub *cub)
{
	if (!ft_temporary(line, cub))
		return (0);
	if (!ft_check_map(cub))
		return (0);
	ft_printf("_______________\n\n");
	ft_printf("MAP CHECKED IN\n");
	ft_printf("_______________\n\n");
	ft_disp_map_ok(cub);
	return (1);
}
