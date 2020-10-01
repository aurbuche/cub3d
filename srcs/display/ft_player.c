/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 11:53:21 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 10:05:50 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_plane(t_cub *cub)
{
	if (cub->ori == 'N')
	{
		cub->plane.x = 0;
		cub->plane.y = ((double)FOV / (double)100);
	}
	if (cub->ori == 'S')
	{
		cub->plane.x = 0;
		cub->plane.y = -((double)FOV / (double)100);
	}
	if (cub->ori == 'E')
	{
		cub->plane.x = ((double)FOV / (double)100);
		cub->plane.y = 0;
	}
	if (cub->ori == 'W')
	{
		cub->plane.x = -((double)FOV / (double)100);
		cub->plane.y = 0;
	}
}

void		ft_dir(t_cub *cub)
{
	cub->pos.x = (double)cub->maps.x + (double)0.5;
	cub->pos.y = (double)cub->maps.y + (double)0.5;
	if (cub->ori == 'N')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
	}
	if (cub->ori == 'S')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
	}
	if (cub->ori == 'E')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
	}
	if (cub->ori == 'W')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
	}
	ft_plane(cub);
}

void		ft_start_player_pos(char c, t_cub *cub, size_t x, size_t y)
{
	if (cub->ori)
		cub->player = 2;
	cub->ori = c;
	cub->maps.x = x;
	cub->maps.y = y;
}
