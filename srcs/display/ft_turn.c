/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:58:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/06 13:47:39 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			ft_turn(t_cub *c)
{
	t_vect		old_dir;
	t_vect		old_plane;

	old_dir.x = c->dir.x;
	old_plane.x = c->plane.x;
	if (c->turn == 'R')
	{
		c->dir.x = c->dir.x * cos(-ROTSPEED) - c->dir.y * sin(-ROTSPEED);
		c->dir.y = old_dir.x * sin(-ROTSPEED) + c->dir.y * cos(-ROTSPEED);
		c->plane.x = c->plane.x * cos(-ROTSPEED) - c->plane.y * sin(-ROTSPEED);
		c->plane.y = old_plane.x * sin(-ROTSPEED) + c->plane.y * cos(-ROTSPEED);
	}
	else if (c->turn == 'L')
	{
		c->dir.x = c->dir.x * cos(ROTSPEED) - c->dir.y * sin(ROTSPEED);
		c->dir.y = old_dir.x * sin(ROTSPEED) + c->dir.y * cos(ROTSPEED);
		c->plane.x = c->plane.x * cos(ROTSPEED) - c->plane.y * sin(ROTSPEED);
		c->plane.y = old_plane.x * sin(ROTSPEED) + c->plane.y * cos(ROTSPEED);
	}
}
