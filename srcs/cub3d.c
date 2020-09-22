/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:25:11 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 16:33:59 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int			ft_start(int ac, char **av, int level)
{
	char		*line;
	t_cub		*cub;

	cub = ft_init_cub();
	line = NULL;
	if (!(ft_check_cub(ac, av, cub)))
		return (-1);
	cub->malloc = 1;
	cub->n_ruby = 0;
	cub->level = level;
	ft_parse(line, cub);
	close(cub->fd);
	ft_begin_disp(cub);
	ft_free_cub(cub);
	free(cub);
	return (0);
}

void		ft_free_cub(t_cub *cub)
{
	size_t		i;

	i = 0;
	while (i < cub->n_line)
	{
		free(cub->map[i]);
		i++;
	}
	if (cub->zbuf)
		free(cub->zbuffer);
	if (cub->map_analyze)
		free(cub->map);
	ft_delete(&cub->no);
	ft_delete(&cub->so);
	ft_delete(&cub->ea);
	ft_delete(&cub->we);
	ft_delete(&cub->s);
}

int			main(int ac, char **av)
{
	ft_start(ac, av, 0);
	return (0);
}
