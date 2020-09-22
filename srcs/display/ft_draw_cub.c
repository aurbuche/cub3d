/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:22:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 18:42:14 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void		ft_draw_wall(t_cub *c, int x)
{
	int			i;
	size_t		dist;
	t_color		color;

	i = c->start_draw;
	while (i < c->end_draw)
	{
		dist = i * 256 - c->res[1] * 128 + c->text[c->tex_num].height * 128;
		c->tex.y = (int)c->tex_pos & (dist * c->text[c->tex_num].height - 1);
		c->tex_pos += c->tex_step;
		color.color = c->text[c->tex_num].img_data
				[c->tex.y * c->text[c->tex_num].width + c->tex.x];
		c->screen.img_data[i * c->res[0] + x] = color.color;
		i++;
	}
}

static void		ft_draw_floor(t_cub *c, int x)
{
	int			y;

	y = c->res[1] - 1;
	while (y >= c->end_draw && y > 0)
	{
		c->screen.img_data[y * c->res[0] + x] = c->color_floor;
		y--;
	}
}

static	void	ft_draw_ceil(t_cub *c, int k)
{
	int			x;
	t_color		color;

	x = 0;
	color.color = c->color_ceiling;
	while (x < c->start_draw)
	{
		c->screen.img_data[x * c->res[0] + k] = color.color;
		x++;
	}
}

void			ft_draw(t_cub *c, int x)
{
	ft_draw_floor(c, x);
	ft_draw_ceil(c, x);
	ft_draw_wall(c, x);
}
