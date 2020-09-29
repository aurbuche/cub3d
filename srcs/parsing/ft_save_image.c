/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:15:44 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 09:12:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void	ft_image(t_cub *c, int fd, t_bpm_info bi)
{
	int				x;
	int				y;
	int				bl;
	unsigned char	color[3];

	write(fd, &bi, sizeof(bi));
	y = c->res[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->res[0])
		{
			bl = c->screen.img_data[y * c->res[0] + x];
			color[0] = bl % 256;
			bl /= 256;
			color[1] = bl % 256;
			bl /= 256;
			color[2] = bl % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void		ft_save_image(t_cub *c, char *filename)
{
	t_bpm_file		bf;
	t_bpm_info		bi;
	int				fd;

	ft_memcpy(&bf.bmp_type, "BM", 2);
	bf.size = c->res[0] * c->res[1] * 4 + 54;
	bf.reserved1 = 0;
	bf.reserved2 = 0;
	bf.off_bits = 0;
	bi.size = sizeof(bi);
	bi.width = c->res[0];
	bi.height = c->res[1];
	bi.plane = 1;
	bi.bit_count = 24;
	bi.compression = 0;
	bi.size_image = c->res[0] * c->res[1] * 4 + 54;
	bi.ppmx = 2;
	bi.ppmy = 2;
	bi.clr_used = 0;
	bi.clr_important = 0;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bf, 14);
	ft_image(c, fd, bi);
	ft_close(c);
}
