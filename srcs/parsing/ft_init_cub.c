/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:03:57 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 16:57:26 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void		ft_init_itab(int i, int tab[])
{
	int		x;

	x = 0;
	while (x < i)
	{
		tab[x] = 0;
		x++;
	}
}

static void		ft_init_2(t_cub *cub)
{
	cub->color_floor = 0;
	cub->color_ceiling = 0;
	cub->wall_dist = 0.0;
	cub->sp = 0;
	cub->reso = 0;
	cub->zbuf = 0;
	cub->map_analyze = 0;
}

t_cub			*ft_init_cub(void)
{
	t_cub	*cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		return (NULL);
	cub->n_line = 0;
	cub->n_sprite = 0;
	cub->fd = -1;
	cub->c = 0;
	cub->f = 0;
	cub->move = 0;
	cub->turn = 0;
	cub->ori = 0;
	cub->end = 0;
	cub->ishit = 0;
	cub->no = NULL;
	cub->so = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	cub->s = NULL;
	ft_init_2(cub);
	ft_init_itab(2, cub->res);
	return (cub);
}
