/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:59:45 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/07 14:37:53 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void				r_converter(size_t i, char *line, t_cub *cub)
{
	char	*tmp;
	int		j;
	int		k;

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
		ft_delete(&tmp);
	}
}
