/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:10:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 14:13:35 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void            ft_draw_sprites(t_cub *c)
{
	int		i;
	int		y;
	int		d;

	i = 0;
	while (i < c->n_sprite)
	{
		c->sprite.x = c->sprites[i].pos.x - c->pos.x;
		c->sprite.y = c->sprites[i].pos.y - c->pos.y;
		
		i++;
	}
}