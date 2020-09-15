/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:51:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 14:13:27 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void			ft_sort_sprite(t_cub *c)
{
	size_t		i;
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
			i = 0;
		}
		i++;
	}
}

void				ft_raycast_sprite(t_cub *c)
{
	int		i;

	i = 0;
	i++;
	c->end = 0;
	ft_sort_sprite(c);
	ft_draw_sprites(c);
}