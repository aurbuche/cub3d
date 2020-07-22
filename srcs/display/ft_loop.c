/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:43 by user42            #+#    #+#             */
/*   Updated: 2020/07/22 14:06:53 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			cub_loop(t_cub *cub)
{
    if (cub->move)
        ft_move(cub);
    // if (cub->turn)
    //     ft_turn(cub);
    // mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win, cub->screen.img, 0, 0);
	return (1);
}