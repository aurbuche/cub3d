/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ea_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:01:04 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 11:35:14 by user42           ###   ########lyon.fr   */
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
