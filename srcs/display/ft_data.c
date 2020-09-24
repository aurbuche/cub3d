/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:54:53 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 10:20:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			ft_data(t_cub *c)
{
	if (c->side == 0)
		c->wall_dist = (c->maps.x - c->pos.x
		+ (1 - c->step.x) / 2) / c->dir_ray.x;
	else
		c->wall_dist = (c->maps.y - c->pos.y
		+ (1 - c->step.y) / 2) / c->dir_ray.y;
	c->line_height = (int)(c->res[1] / c->wall_dist);
	c->start_draw = -c->line_height / 2 + c->res[1] / 2;
	if (c->start_draw < 0)
		c->start_draw = 0;
	c->end_draw = c->line_height / 2 + c->res[1] / 2;
	if (c->end_draw >= c->res[1])
		c->end_draw = c->res[1] - 1;
}
