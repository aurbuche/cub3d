/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:10:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/17 10:09:48 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void            ft_draw_sprites(t_cub *c)
{
	c->stripe = c->sprite_draw_start.x;
	while (c->stripe < c->sprite_draw_end.x)
	{
		c->tex.x = (int)((256 * (c->stripe -
			(-c->sprite_width / 2 + c->sprite_screen_x))
			* c->text[5].width / c->sprite_width) / 256);
		// if (c->transform.y > 0 && c->stripe > 0
		// 	&& c->stripe < c->res[0]
		// 	&& c->transform.y < c->zbuffer[c->stripe])
		// 	ft_draw_on_display(c);
		c->stripe++;
	}
}