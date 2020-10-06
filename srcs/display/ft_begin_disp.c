/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_disp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:10:49 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/10/06 13:36:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			unused_key(int key, t_cub *cub)
{
	if (key == K_W)
		cub->move = 0;
	else if (key == K_S)
		cub->move = 0;
	else if (key == K_A)
		cub->move = 0;
	else if (key == K_D)
		cub->move = 0;
	else if (key == K_SPACE)
		cub->move = 0;
	else if (key == K_ARROW_RIGHT)
		cub->turn = 0;
	else if (key == K_ARROW_LEFT)
		cub->turn = 0;
	return (1);
}

int			use_key(int key, t_cub *cub)
{
	if (key == K_ESCAPE)
		ft_close(cub);
	if (key == K_W)
		cub->move = 'W';
	else if (key == K_S)
		cub->move = 'S';
	else if (key == K_A)
		cub->move = 'A';
	else if (key == K_D)
		cub->move = 'D';
	else if (key == K_SPACE)
		cub->move = ' ';
	else if (key == K_ARROW_RIGHT)
		cub->turn = 'R';
	else if (key == K_ARROW_LEFT)
		cub->turn = 'L';
	return (1);
}

int			ft_begin_disp(t_cub *cub)
{
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	ft_dir(cub);
	ft_start_window(cub);
	if (cub->flag == 's')
	{
		ft_raycasting(cub);
		ft_save_image(cub, "screen.bmp");
	}
	mlx_hook(cub->mlx_win, 02, 1L << 0, &use_key, cub);
	mlx_hook(cub->mlx_win, 03, 1L << 1, &unused_key, cub);
	mlx_hook(cub->mlx_win, 33, 1L << 17, &ft_close, cub);
	mlx_loop_hook(cub->mlx_ptr, &cub_loop, cub);
	mlx_loop(cub->mlx_ptr);
	return (1);
}
