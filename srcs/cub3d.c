/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:32:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/22 14:44:48 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int			ft_start(int ac, char **av, t_cub *cub)
{
	char		*line;

	line = NULL;
	if(!(ft_check_cub(ac, av, cub)))
		return(-1);
	ft_parse(line, cub);
	// dprintf(1, "R:\t[%d, %d]\n", cub->res[0], cub->res[1]);
	// dprintf(1, "NO:\t%s\n", cub->no);
	// dprintf(1, "SO:\t%s\n", cub->so);
	// dprintf(1, "WE:\t%s\n", cub->we);
	// dprintf(1, "EA:\t%s\n", cub->ea);
	// dprintf(1, "F:\t[%d, %d, %d]\n", cub->f_color[0], cub->f_color[1], cub->f_color[2]);
	// dprintf(1, "C:\t[%d, %d, %d]\n", cub->c_color[0], cub->c_color[1], cub->c_color[2]);
	// dprintf(1, "S:\t%s\n", cub->s);
	close(cub->fd);
	return (0);
}

int     	main(int ac, char **av)
{
	t_cub		*cub;

	cub = ft_init_cub();
	ft_start(ac, av, cub);
	free(cub);
}
