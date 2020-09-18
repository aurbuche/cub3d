/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_set_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:46:01 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 09:54:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int		ft_abs(int	n)
{
	return (n < 0 ? -n : n);
}

void	ft_sprite_set_draw(t_cub *c)
{
	c->sprite_height = ft_abs((int)(c->res[1] / (c->transform.y)));
	c->sprite_draw_start.y = (-c->sprite_height / 2 + c->res[1] / 2);
	if (c->sprite_draw_start.y < 0)
		c->sprite_draw_start.y = 0;
	c->sprite_draw_end.y = (c->sprite_height / 2 + c->res[1] / 2);
	if (c->sprite_draw_end.y >= c->res[1])
		c->sprite_draw_end.y = c->res[1] - 1;
	c->sprite_width = ft_abs((int)(c->res[1] / (c->transform.y)));
	c->sprite_draw_start.x = -c->sprite_width / 2 + c->sprite_screen_x;
	if (c->sprite_draw_start.x < 0)
		c->sprite_draw_start.x = 0;
	c->sprite_draw_end.x = c->sprite_width / 2 + c->sprite_screen_x;
	if (c->sprite_draw_end.x >= c->res[0])
		c->sprite_draw_end.x = c->res[0] - 1;
}