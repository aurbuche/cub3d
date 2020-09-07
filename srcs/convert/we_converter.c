/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   we_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:01:03 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 11:24:50 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			we_converter(size_t i, char *line, t_cub *cub)
{
	int			j;

	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->we = ft_strndup(line + j, i);
}
