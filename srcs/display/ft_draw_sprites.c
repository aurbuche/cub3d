/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:10:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 13:50:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void            ft_draw_sprites(t_cub *c, int i)
{
	while (i < c->n_sprite)
	{
		c->sprite.x = c->sprites[i].pos.x - c->pos.x;
		c->sprite.y = c->sprites[i].pos.y - c->pos.y;
		c->inv_det = 1.0 / ((c->plane.x * c->dir.y) - (c->dir.x * c->plane.y));
		c->transform.x = c->inv_det * (c->dir.y * c->sprite.x - c->dir.x * c->sprite.y);
		c->transform.y = c->inv_det * (-c->plane.y * c->sprite.x + c->plane.x * c->sprite.y);
		c->sprite_screen_x = (int)(c->res[0] / 2) * (1 + c->transform.x / c->transform.y);
		ft_sprite_set_draw(c);
		i++;
	}
}