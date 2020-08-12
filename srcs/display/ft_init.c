/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:01 by user42            #+#    #+#             */
/*   Updated: 2020/08/12 11:05:25 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			ft_init_colors(t_color color, t_cub *cub, char *line)
{
	color.argb[0] = cub->f_color[0];
	color.argb[1] = cub->f_color[1];
	color.argb[2] = cub->f_color[2];
	dprintf(1, "[%d]", cub->f_color[0]);
	dprintf(1, "[%d]", color.argb[0]);
	if (line[0] == 'F')
		  cub->color_floor = color.color;
	if (line[0] == 'C')
		  cub->color_ceiling = color.color;
}

void			ft_colors(t_cub *cub, char *line)
{
	t_color		color;

	color.argb[3] = 0;
	ft_init_colors(color, cub, line);
}
