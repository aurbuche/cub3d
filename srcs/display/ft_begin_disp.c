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

int			ft_begin_disp(t_cub *cub)
{
	t_data			data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cub->res[0], cub->res[1], "Hello World")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
	// if (())
	return (1);
}