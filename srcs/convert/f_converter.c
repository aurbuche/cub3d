/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:14:06 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/23 16:06:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void				f_converter(size_t i, char *line, t_cub *cub)
{
	char	*tmp;
	int		j;
	int		k;

	k = ft_check_color(line, cub);
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
		cub->f_color[k] = ft_strdup(tmp);
		i++;
		if (i >= ft_strlen(line))
			i = ft_strlen(line);
		k++;
		ft_delete(&tmp);
	}
	ft_colors(cub, line);
}
