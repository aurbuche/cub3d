/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:42:56 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 18:39:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int		ft_load_noso_text(t_cub *c)
{
	if ((c->text[0].img = mlx_xpm_file_to_image(c->mlx_ptr, c->no,
		&c->text[0].width, &c->text[0].height)))
		c->text[0].img_data = (int *)mlx_get_data_addr(c->text[0].img,
			&c->text[0].bpp, &c->text[0].size_line, &c->text[0].endian);
	else
		exit(1);
	if ((c->text[1].img = mlx_xpm_file_to_image(c->mlx_ptr, c->so,
		&c->text[1].width, &c->text[1].height)))
		c->text[1].img_data = (int *)mlx_get_data_addr(c->text[1].img,
			&c->text[1].bpp, &c->text[1].size_line, &c->text[1].endian);
	else
		exit(1);
	return (0);
}

static int		ft_load_eawe_text(t_cub *c)
{
	if ((c->text[2].img = mlx_xpm_file_to_image(c->mlx_ptr, c->ea,
		&c->text[2].width, &c->text[2].height)))
		c->text[2].img_data = (int *)mlx_get_data_addr(c->text[2].img,
			&c->text[2].bpp, &c->text[2].size_line, &c->text[2].endian);
	else
		exit(1);
	if ((c->text[3].img = mlx_xpm_file_to_image(c->mlx_ptr, c->we,
		&c->text[3].width, &c->text[3].height)))
		c->text[3].img_data = (int *)mlx_get_data_addr(c->text[3].img,
			&c->text[3].bpp, &c->text[3].size_line, &c->text[3].endian);
	else
		exit(1);
	return (0);
}

static int		ft_load_sprite_texture(t_cub *c)
{
	if ((c->text[4].img = mlx_xpm_file_to_image(c->mlx_ptr, c->s,
		&c->text[4].width, &c->text[4].height)))
		c->text[4].img_data = (int *)mlx_get_data_addr(c->text[4].img,
			&c->text[4].bpp, &c->text[4].size_line, &c->text[4].endian);
	else
		exit(1);
	return (0);
}

void			ft_textures(t_cub *c)
{
	ft_load_noso_text(c);
	ft_load_eawe_text(c);
	ft_load_sprite_texture(c);
}

void			ft_apply_textures(t_cub *c)
{
	if (!c->side)
		c->tex_num = c->dir_ray.x < 0 ? 1 : 0;
	else
		c->tex_num = c->dir_ray.y < 0 ? 2 : 3;
	if (c->side == 0)
		c->wall.x = c->pos.y + c->wall_dist * c->dir_ray.y;
	else
		c->wall.x = c->pos.x + c->wall_dist * c->dir_ray.x;
	c->wall.x -= (int)c->wall.x;
	c->tex.x = (int)(c->wall.x * c->text[c->tex_num].width);
	if (c->side == 0 && c->dir_ray.x > 0)
		c->tex.x = c->text[c->tex_num].width - c->tex.x - 1;
	if (c->side == 1 && c->dir_ray.y < 0)
		c->tex.x = c->text[c->tex_num].width - c->tex.x - 1;
	c->tex_step = 1.0 * c->text[c->tex_num].height / c->line_height;
	c->tex_pos =
		(c->start_draw - c->res[1] / 2 + c->line_height / 2) * c->tex_step;
}
