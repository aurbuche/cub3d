/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:42:56 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/04 17:32:14 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int	ft_load_nose_textures(t_cub *c)
{
	if (!(c->text[0].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->no,
		&c->text[0].width, &c->text[0].height)))
		return (EXIT_FAILURE);
	if (!(c->text[0].img_data =
		(int *)mlx_get_data_addr(c->text[0].img, &c->text[0].bpp,
		&c->text[0].size_line, &c->text[0].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[1].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->so,
		&c->text[1].width, &c->text[1].height)))
		return (EXIT_FAILURE);
	if (!(c->text[1].img_data =
		(int *)mlx_get_data_addr(c->text[1].img, &c->text[1].bpp,
		&c->text[1].size_line, &c->text[1].endian)))
		return (EXIT_FAILURE);
	return (0);
}

static int	ft_load_eawe_textures(t_cub *c)
{
	if (!(c->text[2].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->ea, &c->text[2].width,
		&c->text[2].height)))
		return (EXIT_FAILURE);
	if (!(c->text[2].img_data =
		(int *)mlx_get_data_addr(c->text[2].img, &c->text[2].bpp,
		&c->text[2].size_line, &c->text[2].endian)))
		return (EXIT_FAILURE);
	if (!(c->text[3].img =
		mlx_xpm_file_to_image(c->mlx_ptr, c->we, &c->text[3].width,
		&c->text[3].height)))
		return (EXIT_FAILURE);
	if (!(c->text[3].img_data =
		(int *)mlx_get_data_addr(c->text[3].img, &c->text[3].bpp,
		&c->text[3].size_line, &c->text[3].endian)))
		return (EXIT_FAILURE);
	return (0);
}

void        ft_textures(t_cub *cub)
{
	if (ft_load_nose_textures(c))
		ft_error("Failed to load textures");
	if (ft_load_eawe_textures(c))
		ft_error("Failed to load textures");
}
