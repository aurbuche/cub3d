/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:03:57 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/17 14:22:44 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_init_ctab(int i, char *tab[])
{
	int		x;

	x = 0;
	while (x < i)
	{
		tab[x] = NULL;;
		x++;
	}
}

void		ft_init_itab(int i, int tab[])
{
	int		x;

	x = 0;
	while (x < i)
	{
		tab[x] = 0;
		x++;
	}
}

t_cub		*ft_init_cub(void)
{
	t_cub	*cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		return (NULL);
	cub->n_line = 0;
	cub->n_sprite = 0;
	cub->fd = 0;
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
	cub->color_floor = 0;
	cub->color_ceiling = 0;
	cub->wall_dist = 0.0;
	ft_init_itab(2, cub->res);
	return (cub);
}
