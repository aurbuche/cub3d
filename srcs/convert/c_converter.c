/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:46:05 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/07 20:12:39 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void				c_converter(size_t i, char *line, t_cub *cub)
{
	char	*tmp;
	int		j;
	int		k;

	k = 0;
	if (cub->color_ceiling)
		ft_disp_error("Ceiling color already exist.", cub);
	ft_printf("%d\n", cub->color_ceiling);
	while (line[i])
	{
		j = 0;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			j = i;
			while (ft_isdigit(line[i]))
				i++;
			tmp = ft_strndup(line + j, i - 1);
		}
		cub->c_color[k] = ft_strdup(tmp);
		i++;
		if (i >= ft_strlen(line))
			i = ft_strlen(line);
		k++;
		ft_delete(&tmp);
	}
	ft_colors(cub, line);
	ft_printf("%d\n", cub->color_ceiling);
	cub->c = 1;
}
