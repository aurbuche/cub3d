/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 10:24:24 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/24 08:27:12 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			ft_check_corridor(size_t i, size_t j, t_cub *cub)
{
	if (!ft_strchr("NSEW012", cub->map[i][j + 1])
		|| (!ft_strchr("NSEW012", cub->map[i + 1][j])))
	{
		ft_disp_error("Map is not close!");
		return (0);
	}
	return (1);
}

int			ft_check_inside(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub->n_line - 1)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
				if (!ft_check_corridor(i, j, cub))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
