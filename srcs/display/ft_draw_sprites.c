/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:10:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 18:30:20 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void		ft_draw_two(t_cub *c)
{
	t_color		color;
	size_t		d;
	int			i;

	i = c->sprite_draw_start.y - 1;
	while (++i < c->sprite_draw_end.y)
	{
		d = i * 256 - c->res[1] * 128 + c->sprite_height * 128;
		c->tex.y = ((d * c->text[4].height) / c->sprite_height) / 256;
		color.color = c->text[4].img_data[c->tex.y
			* c->text[4].width + c->tex.x];
		if ((color.color & 0xffffff) != 0)
			c->screen.img_data[i * c->res[0] + c->stripe] = color.color;
	}
}

void			ft_draw_sprites(t_cub *c)
{
	c->stripe = c->sprite_draw_start.x;
	while (c->stripe < c->sprite_draw_end.x)
	{
		c->tex.x = (int)((256 * (c->stripe -
			(-c->sprite_width / 2 + c->sprite_screen_x))
			* c->text[4].width / c->sprite_width) / 256);
		if (c->transform.y > 0 && c->stripe > 0
			&& c->stripe < c->res[0]
			&& c->transform.y < c->zbuffer[c->stripe])
			ft_draw_two(c);
		c->stripe++;
	}
}
