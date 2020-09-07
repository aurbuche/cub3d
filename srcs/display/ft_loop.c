/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:43 by user42            #+#    #+#             */
/*   Updated: 2020/09/07 10:34:17 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			cub_loop(t_cub *c)
{
	if (c->turn && !c->end)
		ft_turn(c);
	if (c->move && !c->end)
		ft_move(c);
	if (!c->end)
		ft_raycasting(c);
	if (c->end)
		ft_close(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->screen.img, 0, 0);
	return (1);
}
