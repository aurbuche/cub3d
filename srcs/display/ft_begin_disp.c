/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_disp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:10:49 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/15 09:21:15 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libcub3d.h"

int			deal_key(int key)
{
	ft_putnbr(key);
	return (1);
}

int			ft_begin_disp(t_cub *cub)
{
	t_data		data;
	// int			x;
	// int			y;
	// int			color;

	// x = 0;
	// color = 0xffffff;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cub->res[0], cub->res[1], "Hello World")) == NULL)
		return (EXIT_FAILURE);
	// while (x < cub->res[0])
	// {
	// 	y = 0;
	// 	while (y < cub->res[1])
	// 	{
	// 		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, color);
	// 		y++;
	// 	}
	// 	x++;
	// }
	mlx_key_hook(data.mlx_win, deal_key, (void *)0);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
	// // if (())
	return (1);
}