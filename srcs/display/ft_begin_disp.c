/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_disp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:10:49 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/24 09:49:34 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libcub3d.h"

int			unused_key(int key, t_cub *cub)
{
	if (key == K_W)
		cub->move =  0;
	else if (key == K_S)
		cub->move = 0;
	else if (key == K_A)
		cub->move = 0;
	else if (key == K_D)
		cub->move = 0;
	else if (key == K_SPACE)
		cub->move = 0;
	return (1);
}

int			use_key(int key, t_cub *cub)
{
	if (key == K_ESCAPE)
		ft_close(cub);
	if (key == K_W)
		cub->move = 'w';
	else if (key == K_S)
		cub->move = 's';
	else if (key == K_A)
		cub->move = 'a';
	else if (key == K_D)
		cub->move = 'd';
	else if (key == K_SPACE)
		cub->move = ' ';
	return (1);
}

int			ft_begin_disp(t_cub *cub)
{
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	/***/
	// if (!(cub->screen.img = mlx_new_image(cub->mlx_ptr, cub->res[0], cub->res[1])))
	// 	return (EXIT_FAILURE);
	if ((cub->mlx_win = mlx_new_window(cub->mlx_ptr, cub->res[0], cub->res[1], "Hello World")) == NULL)
		return (EXIT_FAILURE);
	/***/
	// ft_draw_ceiling(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, &use_key, cub);
	mlx_hook(cub->mlx_win, 3, 1l << 1, &unused_key, cub);
	mlx_loop_hook(cub->mlx_ptr, &cub_loop, cub);
	mlx_loop(cub->mlx_ptr);
	return (EXIT_SUCCESS);
	return (1);
}
