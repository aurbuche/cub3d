/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ea_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:01:04 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/23 14:59:46 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void				ea_converter(size_t i, char *line, t_cub *cub)
{
	int			j;

	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->ea = ft_strndup(line + j, i - 1);
}
