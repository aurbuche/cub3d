/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:00:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/08/11 11:24:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void			no_converter(size_t i, char *line, t_cub *cub)
{
	int			j;

	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->no = ft_strndup(line + j, i);
}
