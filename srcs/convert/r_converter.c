/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:59:45 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/24 11:38:17 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int			r_converter_2(size_t i, char *line, char **tmp)
{
	size_t		j;

	j = i;
	while (ft_isdigit(line[i]))
		i++;
	*tmp = ft_strndup(line + j, i - 1);
	return (i);
}

static void			ft_check_reso(t_cub *c)
{
	if (c->res[0] > 1500)
		c->res[0] = 1500;
	if (c->res[0] <= 0)
		ft_disp_error("Width can't be inferior or egal to zero", c);
	if (c->res[0] < 500)
		c->res[0] = 500;
	if (c->res[1] > 1000)
		c->res[1] = 1000;
	if (c->res[1] <= 0)
		ft_disp_error("Height can't be inferior or egal to zero", c);
	if (c->res[1] < 500)
		c->res[1] = 500;
	if (c->res[0] < c->res[1])
		c->res[0] = c->res[1];
}

void				r_converter(size_t i, char *line, t_cub *cub)
{
	char	*tmp;
	int		k;

	k = 0;
	if (cub->reso)
		ft_disp_error("Arg already exist", cub);
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			i = r_converter_2(i, line, &tmp);
		cub->res[k] = ft_atoi(tmp);
		i++;
		if (i >= ft_strlen(line))
			i = ft_strlen(line);
		k++;
		ft_delete(&tmp);
	}
	ft_check_reso(cub);
	cub->reso = 1;
}
