/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:17:15 by user42            #+#    #+#             */
/*   Updated: 2020/09/04 17:40:08 by user42           ###   ########lyon.fr   */
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

// static void		ft_moverl(t_cub *c)
// {
// 	if (c->move == 'D')
// 	{
// 		c->pos.x += c->plane.x * MOVESPEED;
// 		if (c->map[(int)c->pos.x][(int)c->pos.y] == '1')

// 	}
// }

void			ft_move(t_cub *c)
{
	ft_movefb(c);
	// ft_moverl(c);
}
