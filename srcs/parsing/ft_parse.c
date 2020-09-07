/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:45:52 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/07 18:08:39 by user42           ###   ########lyon.fr   */
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

int					ft_convert(char *line, t_cub *cub)
{
	size_t		i;

	i = 0;
	if (line[i] == 'R')
		r_converter(i, line, cub);
	else if (line[i] == 'F')
		f_converter(i, line, cub);
	else if (line[i] == 'C')
		c_converter(i, line, cub);
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
	if (!ft_map_analyze(line, cub))
		return (0);
	return (1);
}
