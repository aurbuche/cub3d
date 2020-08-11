/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:42:56 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 11:43:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"
 
static int	ft_load_noso_text(t_cub *cub)
{
	if ((cub->text[0].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->no, &cub->text[0].width, &cub->text[0].height)))
		cub->text[0].img_data = (int *)mlx_get_data_addr(cub->text[0].img, &cub->text[0].bpp, &cub->text[0].size_line, &cub->text[0].endian);
	else
		dprintf(1, "prout");
	if ((cub->text[1].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->so, &cub->text[1].width, &cub->text[1].height)))
		cub->text[1].img_data = (int *)mlx_get_data_addr(cub->text[1].img, &cub->text[1].bpp, &cub->text[1].size_line, &cub->text[1].endian);
	else
		exit(1);
	return (0);
}

static int	ft_load_eawe_text(t_cub *cub)
{
	if ((cub->text[2].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->ea, &cub->text[2].width, &cub->text[2].height)))
		cub->text[2].img_data = (int *)mlx_get_data_addr(cub->text[2].img, &cub->text[2].bpp, &cub->text[2].size_line, &cub->text[2].endian);
	else
		exit(1);
	if ((cub->text[3].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->we, &cub->text[3].width, &cub->text[3].height)))
		cub->text[3].img_data = (int *)mlx_get_data_addr(cub->text[3].img, &cub->text[3].bpp, &cub->text[3].size_line, &cub->text[3].endian);
	else
		exit(1);
	return (0);
}

void        ft_textures(t_cub *cub)
{
	ft_load_noso_text(cub);
	ft_load_eawe_text(cub);
}
