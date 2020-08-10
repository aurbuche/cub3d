/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:43 by user42            #+#    #+#             */
/*   Updated: 2020/08/06 10:23:20 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			cub_loop(t_cub *cub)
{
	dprintf(1, "%c", cub->move);
	if (cub->move)
		ft_move(cub);
	if (cub->turn)
		ft_turn(cub);
	if (!cub->end)
		ft_raycasting(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win, cub->screen.img, 0, 0);
	return (1);
}
