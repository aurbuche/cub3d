/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:59:45 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/08 22:17:20 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void        r_converter(size_t i, char *line, t_cub *cub)
{
    char    *tmp;
    int     j;
    int     k;
    
    k = 0;
    while (line[i])
    {
        j = 0;
        while (line[i] && !ft_isdigit(line[i]))
            i++;
        if (ft_isdigit(line[i]))
        {
            j = i;
            while (ft_isdigit(line[i]))
                i++;
            tmp = ft_strndup(line + j, i - 1);
        }
        cub->res[k] = ft_atoi(tmp);
        i++;
        if (i >= ft_strlen(line))
            i = ft_strlen(line);
        k++;
    }
}
