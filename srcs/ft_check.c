/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:51:41 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/22 11:32:55 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int			ft_1_line(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("1 ", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_wall(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("NSEW012\n", str[i]))
		{
			ft_disp_error("Wrong character use in the map!");
			return(0);
		}
		i++;
	}
	if (!ft_strchr("1 ", str[0]) || !ft_strchr("1 ", str[i - 1]))
	{
		ft_disp_error("The map is not close!");
		return (0);
	}
	return (1);
}

int			ft_check_map(t_cub *cub)
{
	size_t		i;

	i = 1;
	if (!ft_1_line(cub->map[0]) ||
		!ft_1_line(cub->map[cub->n_line - 1]))
	{
		ft_disp_error("The map is not close!");
		return (0);
	}
	while (i <= cub->n_line - 2)
	{
		if (!ft_check_wall(cub->map[i]))
			return (0);
		i++;
	}
	if (!ft_check_inside(cub))
		return(0);
	return (1);
}

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