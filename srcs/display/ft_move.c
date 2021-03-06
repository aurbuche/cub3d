/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:17:15 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 09:38:25 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_movefb(t_cub *c)
{
	c->maps.x = (int)c->pos.x;
	c->maps.y = (int)c->pos.y;
	if (c->map[(int)c->pos.x][(int)c->pos.y] == '2')
	{
		c->map[(int)c->pos.x][(int)c->pos.y] = '0';
		c->n_ruby++;
	}
	if (c->move == 'W')
	{
		c->pos.x += c->dir.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->dir.x * MOVESPEED;
		c->pos.y += c->dir.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->dir.y * MOVESPEED;
	}
	else if (c->move == 'S')
	{
		c->pos.x -= c->dir.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->dir.x * MOVESPEED;
		c->pos.y -= c->dir.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->dir.y * MOVESPEED;
	}
}

void		ft_moverl(t_cub *c)
{
	c->maps.x = (int)c->pos.x;
	c->maps.y = (int)c->pos.y;
	if (c->map[(int)c->pos.x][(int)c->pos.y] == '2')
	{
		c->map[(int)c->pos.x][(int)c->pos.y] = '0';
		c->n_ruby++;
	}
	if (c->movead == 'D')
	{
		c->pos.x += c->plane.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x -= c->plane.x * MOVESPEED;
		c->pos.y += c->plane.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y -= c->plane.y * MOVESPEED;
	}
	else if (c->movead == 'A')
	{
		c->pos.x -= c->plane.x * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.x += c->plane.x * MOVESPEED;
		c->pos.y -= c->plane.y * MOVESPEED;
		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')
			c->pos.y += c->plane.y * MOVESPEED;
	}
}
