/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:22:46 by user42            #+#    #+#             */
/*   Updated: 2020/08/04 10:54:28 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void            ft_draw_ceil_floor(t_cub *c)
{
    int			i;
	int			j;

	j = -1;
	c->x = -1;
	while (++j < c->res[0] / 2)
	{
		i = -1;
		while (++i < c->res[1])
			c->img_data[j * c->res[0] + i] = c->color_ceiling;
	}
	while (j < c->res[0])
	{
		i = -1;
		while (++i < c->res[1])
			c->img_data[j * c->res[1] + i] = c->color_floor;
	}
	// mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->i)
}

// void            ft_draw_wall(t_cub *cub)
// {
    
// }

void			ft_draw(t_cub *cub)
{
	ft_draw_ceil_floor(cub);
	// cub->screen.img = mlx_new_image(cub->mlx_ptr, cub->res[0], cub->res[1]);

}