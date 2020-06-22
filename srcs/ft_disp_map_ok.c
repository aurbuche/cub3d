/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_map_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:08:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/22 09:24:38 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void            ft_disp_map_ok(t_cub *cub)
{
    size_t      i;
    size_t      j;

    i = 0;
    ft_printf("_______________\n\n");
	ft_printf("MAP CHECKED IN\n");
    ft_printf("_______________\n\n");
    while (i < cub->n_line)
    {
        j = 0;
        while (cub->map[i][j] && cub->map[i][j] != '\n')
        {
            if (cub->map[i][j] == '0')
                ft_printf(" ");
            else
                ft_printf("%c", cub->map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}