/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:30:00 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 10:52:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void			ft_setup(t_cub *c, int x)
{
	c->camerax = 2 * x / (double)c->res[0] - 1;
	c->dir_ray.x = c->dir.x + c->plane.x * c->camerax;
	c->dir_ray.y = c->dir.y + c->plane.y * c->camerax;
	c->maps.x = (int)c->pos.x;
	c->maps.y = (int)c->pos.y;
	c->delta_dist.x = fabs(1 / c->dir_ray.x);
	c->delta_dist.y = fabs(1 / c->dir_ray.y);
}

static void			ft_search_wall(t_cub *c)
{
	c->ishit = 0;
	if (c->dir_ray.x < 0)
	{
		c->step.x = -1;
		c->side_dist.x = (c->pos.x - c->maps.x) * c->delta_dist.x;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.x = (c->maps.x + 1.0 - c->pos.x) * c->delta_dist.x;
	}
	if (c->dir_ray.y < 0)
	{
		c->step.y = -1;
		c->side_dist.y = (c->pos.y - c->maps.y) * c->delta_dist.y;
	}
	else
	{
		c->step.y = 1;
		c->side_dist.y = (c->maps.y + 1.0 - c->pos.y) * c->delta_dist.y;
	}
}

static void			dda(t_cub *c)
{
	while (!c->ishit)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->maps.x += c->step.x;
			c->side = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->maps.y += c->step.y;
			c->side = 1;
		}
		if (c->map[(int)c->maps.x][(int)c->maps.y] == '1')
			c->ishit = 1;
	}
}

void				ft_raycasting(t_cub *c)
{
	int		x;

	x = 0;
	while (x < c->res[0])
	{
		ft_setup(c, x);
		ft_search_wall(c);
		dda(c);
		ft_data(c);
		ft_apply_textures(c);
		ft_draw(c, x);
		c->zbuffer[x] = c->wall_dist + 0.0;
		x++;
	}
	ft_raycast_sprite(c);
}
