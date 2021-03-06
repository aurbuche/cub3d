/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:01:01 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/07 16:54:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void				s_converter(size_t i, char *line, t_cub *cub)
{
	int			j;

	j = 0;
	if (cub->s)
		ft_disp_error("Cub->s a deja une valeur", cub);
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->s = ft_strndup(line + j, i);
}
