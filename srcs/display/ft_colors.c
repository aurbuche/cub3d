/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:01 by user42            #+#    #+#             */
/*   Updated: 2020/09/23 16:06:11 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int				ft_check_color(char *line, t_cub *cub)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '.')
			ft_disp_error("Color must be in int", cub);
		i++;
	}
	return (0);
}

int				ft_iscolor(t_cub *cub, char *col)
{
	int		color;

	color = ft_atoi(col);
	if (!(0 <= color && color <= 255))
		ft_disp_error("Color is not in a good format.", cub);
	return (color);
}

void			ft_init_colors(t_color color, t_cub *cub, char *line)
{
	if (line[0] == 'F')
	{
		color.rgb.r = ft_iscolor(cub, cub->f_color[0]);
		color.rgb.g = ft_iscolor(cub, cub->f_color[1]);
		color.rgb.b = ft_iscolor(cub, cub->f_color[2]);
		cub->color_floor = color.color;
		ft_printf("Floor:\n\e[48;2;%d;%d;%dm \e[0m ",
			color.rgb.r, color.rgb.g, color.rgb.b);
		ft_printf("R: %d, G: %d, B: %d\n",
			color.rgb.r, color.rgb.g, color.rgb.b);
	}
	if (line[0] == 'C')
	{
		color.rgb.r = ft_iscolor(cub, cub->c_color[0]);
		color.rgb.g = ft_iscolor(cub, cub->c_color[1]);
		color.rgb.b = ft_iscolor(cub, cub->c_color[2]);
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
