/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:01 by user42            #+#    #+#             */
/*   Updated: 2020/08/13 11:25:52 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			ft_init_colors(t_color color, t_cub *cub, char *line)
{
	if (line[0] == 'F')
	{
		color.argb[0] = cub->f_color[0];
		color.argb[1] = cub->f_color[1];
		color.argb[2] = cub->f_color[2];
		cub->color_floor = color.color;
		ft_printf("%c : %d\n", line[0], color.color);
		ft_printf("%d/%d/%d\n", color.argb[0], color.argb[1], color.argb[2]);
		ft_reset_tab(cub->f_color, 3);
		// ft_reset_tab(color.argb, 3);
	}
	if (line[0] == 'C')
	{
		color.argb[0] = cub->c_color[0];
		color.argb[1] = cub->c_color[1];
		color.argb[2] = cub->c_color[2];
		cub->color_ceiling = color.color;
		ft_reset_tab(cub->c_color, 3);
		ft_printf("%c : %d\n", line[0], color.color);
		ft_printf("%d/%d/%d\n", color.argb[0], color.argb[1], color.argb[2]);
		// ft_reset_tab(color.argb, 3);
	}
}

void			ft_colors(t_cub *cub, char *line)
{
	t_color		color;

	color.color = 0;
	ft_init_colors(color, cub, line);
}
