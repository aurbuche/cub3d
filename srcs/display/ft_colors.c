/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:01 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 18:23:58 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			ft_init_colors(t_color color, t_cub *cub, char *line)
{
	if (line[0] == 'F')
	{
		color.rgb.r = ft_atoi(cub->f_color[0]);
		color.rgb.g = ft_atoi(cub->f_color[1]);
		color.rgb.b = ft_atoi(cub->f_color[2]);
		cub->color_floor = color.color;
		ft_printf("Floor:\n\e[48;2;%d;%d;%dm \e[0m ",
			color.rgb.r, color.rgb.g, color.rgb.b);
		ft_printf("R: %d, G: %d, B: %d\n",
			color.rgb.r, color.rgb.g, color.rgb.b);
	}
	if (line[0] == 'C')
	{
		color.rgb.r = ft_atoi(cub->c_color[0]);
		color.rgb.g = ft_atoi(cub->c_color[1]);
		color.rgb.b = ft_atoi(cub->c_color[2]);
		cub->color_ceiling = color.color;
		ft_printf("Ceil:\n\e[48;2;%d;%d;%dm \e[0m ",
			color.rgb.r, color.rgb.g, color.rgb.b);
		ft_printf("R: %d, G: %d, B: %d\n",
			color.rgb.r, color.rgb.g, color.rgb.b);
	}
}

void			ft_colors(t_cub *cub, char *line)
{
	t_color		color;

	color.color = 0;
	ft_init_colors(color, cub, line);
}
