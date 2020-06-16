/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   we_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:01:03 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/09 11:22:36 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void        we_converter(size_t i, char *line, t_cub *cub)
{
	int			j;
	
	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->we = ft_strndup(line + j, i - 1);
}
