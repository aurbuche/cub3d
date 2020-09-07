/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_map_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:08:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/08 13:21:04 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_disp_map_ok(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub->n_line)
	{
		j = 0;
		while (cub->map[i][j] && cub->map[i][j] != '\n')
		{
			if (cub->map[i][j] == '0')
				ft_printf(" ");
			else if (cub->map[i][j] == '1')
				ft_printf("\e[48;2;%d;%d;%dm \e[0m", 97, 97, 97);
			else if (cub->map[i][j] == '2')
				ft_printf("\e[48;2;%d;%d;%dm \e[0m", 255, 255, 0);
			else if (ft_strchr("NSEW", cub->map[i][j]))
				ft_printf("\e[48;2;%d;%d;%dm \e[0m", 255, 0, 0);
			else
				ft_printf("%c", cub->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
