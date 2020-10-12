/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:43 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 09:33:08 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			cub_loop(t_cub *c)
{
	if (c->end)
		ft_close(c);
	if (c->n_ruby == 3 && !c->end)
		ft_next_level(c);
	if (c->turn && !c->end)
		ft_turn(c);
	if (c->move && !c->end)
		ft_movefb(c);
	if (c->movead && !c->end)
		ft_moverl(c);
	if (!c->end)
		ft_raycasting(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->screen.img, 0, 0);
	return (1);
}
