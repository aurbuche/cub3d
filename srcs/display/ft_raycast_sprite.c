/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:51:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 09:52:38 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void			ft_sort_sprite(t_cub *c)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < c->n_sprite)
	{
		c->sprites[i].dist = sqrt((c->pos.x - c->sprites[i].pos.x) *
			(c->pos.x - c->sprites[i].pos.x) +
			((c->pos.y - c->sprites[i].pos.y) *
			(c->pos.y - c->sprites[i].pos.y)));
		i++;
	}
	i = 0;
	while (i < c->n_sprite - 1)
	{
		if (c->sprites[i].dist < c->sprites[i + 1].dist)
		{
			tmp = c->sprites[i + 1];
			c->sprites[i + 1] = c->sprites[i];
			c->sprites[i] = tmp;
			i = -1;
		}
		i++;
	}
}

void				ft_raycast_sprite(t_cub *c)
{
	int		i;

	i = 0;
	ft_search_sprite(c);
	ft_sort_sprite(c);
	while (i < c->n_sprite)
	{
		c->sprite.x = c->sprites[i].pos.x - c->pos.x;
		c->sprite.y = c->sprites[i].pos.y - c->pos.y;
		c->inv_det = 1.0 / ((c->plane.x * c->dir.y)
			- (c->dir.x * c->plane.y));
		c->transform.x = c->inv_det * ((c->dir.y * c->sprite.x)
			- (c->dir.x * c->sprite.y));
		c->transform.y = c->inv_det * ((-c->plane.y * c->sprite.x)
			+ (c->plane.x * c->sprite.y));
		c->sprite_screen_x = (int)((c->res[0] / 2)
			* (1 + c->transform.x / c->transform.y));
		ft_sprite_set_draw(c);
		ft_draw_sprites(c);
		i++;
	}
}