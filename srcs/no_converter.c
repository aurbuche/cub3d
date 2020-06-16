/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:00:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/09 11:06:43 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void            no_converter(size_t i, char *line, t_cub *cub)
{
	int			j;
	
	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	cub->no = ft_strndup(line + j, i - 1);	
}