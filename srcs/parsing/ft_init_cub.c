/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:03:57 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 09:09:44 by user42           ###   ########lyon.fr   */
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
	cub->fd = 0;
	cub->c = 0;
	cub->f = 0;
	cub->move = 0;
	cub->turn = 0;
	cub->ori = 0;
	cub->end = 0;
	cub->no = NULL;
	cub->so = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	ft_init_itab(3, cub->f_color);
	ft_init_itab(3, cub->c_color);
	ft_init_itab(2, cub->res);
	return (cub);
}
