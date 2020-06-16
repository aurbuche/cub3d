/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:51:41 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/16 08:51:36 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int         ft_check_cub(int ac, char **av, t_cub *cub)
{
	char	*map;
	
	if (ac == 1)
	{
		ft_disp_error("Insert a map please !");
		return(0);
	}
	if (!(map = ft_strrchr(av[1], '.')))
	{
		ft_disp_error("No extension !");
		return (0);
	}
	if (ft_strncmp(".cub", map, 5))
	{
		ft_disp_error("Wrong extension, .cub is better :)");
		return (0);
	}
	if (!(cub->fd = open(av[1], O_RDONLY)))
	{
		ft_disp_error("No map found");
		return (0);
	}
	return(1);
}