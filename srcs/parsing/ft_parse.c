/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:45:52 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/24 10:48:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static int			ft_complete_params(t_cub *cub)
{
	int		i;

	i = cub->res[0] > 0 && cub->res[1] > 0 && cub->no &&
		cub->so && cub->we && cub->ea && cub->s &&
		cub->c != 0 && cub->f != 0;
	return (i);
}

static void			color_converter(size_t i, char *line, t_cub *c)
{
	if (line[i] == 'F' && !c->f)
	{
		c->f = 1;
		f_converter(i, line, c);
	}
	else if (line[i] == 'C' && !c->c)
	{
		c->c = 1;
		c_converter(i, line, c);
	}
	else
		ft_disp_error("One of the two color already exist", c);
}

int					ft_convert(char *line, t_cub *cub)
{
	size_t		i;

	i = 0;
	if (line[i] == 'R')
		r_converter(i, line, cub);
	else if (line[i] == 'F' || line[i] == 'C')
		color_converter(i, line, cub);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		no_converter(i + 2, line, cub);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		so_converter(i + 2, line, cub);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		we_converter(i + 2, line, cub);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ea_converter(i + 2, line, cub);
	else if (line[i] == 'S' && line[i + 1] != 'O')
		s_converter(i + 1, line, cub);
	return (1);
}

int					ft_parse(char *line, t_cub *cub)
{
	while (ft_complete_params(cub) != 1 && get_next_line(cub->fd, &line))
	{
		ft_convert(line, cub);
		free(line);
	}
	if ((!ft_complete_params(cub)))
		ft_disp_error("Missing args", cub);
	else
	{
		ft_print_params(cub);
		ft_printf("_____________________\n\n");
		ft_printf("PARAMETERS COMPLETED\n");
		ft_printf("_____________________\n\n");
	}
	cub->zbuffer = (double *)malloc(sizeof(double) * cub->res[0]);
	cub->zbuf = 1;
	if (!ft_map_analyze(line, cub))
		return (0);
	cub->map_analyze = 1;
	return (1);
}
