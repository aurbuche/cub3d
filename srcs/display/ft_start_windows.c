/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:07:14 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 09:48:50 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			ft_start_window(t_cub *c)
{
	ft_textures(c);
	if (!(c->screen.img = mlx_new_image(c->mlx_ptr, c->res[0], c->res[1])))
		return (EXIT_FAILURE);
	if (!(c->screen.img_data =
		(int*)mlx_get_data_addr(c->screen.img, &c->screen.bpp,
		&c->screen.size_line, &c->screen.endian)))
		return (EXIT_FAILURE);
	if ((c->mlx_win =
		mlx_new_window(c->mlx_ptr, c->res[0], c->res[1], "cub3D")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}