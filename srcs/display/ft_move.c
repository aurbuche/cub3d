/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:17:15 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 11:42:12 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void        ft_movefb(t_cub *c)
{
	if (c->move == 'W')
	{
		c->pos.x += c->dir.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->dir.x *MOVESPEED;
		c->pos.y += c->dir.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->dir.y *MOVESPEED;
	}
	if (c->move == 'S')
	{
		c->pos.x -= c->dir.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->dir.x *MOVESPEED;
		c->pos.y -= c->dir.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->dir.y *MOVESPEED;
	}
}

static void		ft_moverl(t_cub *c)
{
	if (c->move == 'D')
	{
		c->pos.x += c->plane.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->plane.x * MOVESPEED;
		c->pos.y += c->plane.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->plane.y * MOVESPEED;
	}
	if (c->move == 'A')
	{
		c->pos.x -= c->plane.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->plane.x * MOVESPEED;
		c->pos.y -= c->plane.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->plane.y * MOVESPEED;
	}
}

void			ft_move(t_cub *c)
{
	ft_movefb(c);
	c->maps.x = (int)c->pos.x;
	c->maps.y = (int)c->pos.y;
	ft_moverl(c);
	if (c->map[(int)c->pos.x][(int)c->pos.y] == '2')
	{
		c->map[(int)c->pos.x][(int)c->pos.y] = '0';
		c->n_ruby++;
	}
}
