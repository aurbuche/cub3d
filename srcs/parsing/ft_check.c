/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:51:41 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 16:21:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			ft_1_line(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("1 \t", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_wall(char *str, t_cub *cub)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("NSEW012\t \n", str[i]))
			ft_disp_error("Wrong character use in the map!", cub);
		i++;
	}
	if (!ft_strchr("1\t ", str[0]) || !ft_strchr("1\t ", str[i - 1]))
		ft_disp_error("The map is'nt close!", cub);
	return (1);
}

int			ft_check_map(t_cub *cub)
{
	size_t		i;

	i = 1;
	if (!ft_1_line(cub->map[0]) ||
		!ft_1_line(cub->map[cub->n_line - 1]))
		ft_disp_error("The map was not close!", cub);
	while (i <= cub->n_line - 2)
	{
		if (!ft_check_wall(cub->map[i], cub))
			return (0);
		i++;
	}
	if (!ft_check_inside(cub))
		return (0);
	return (1);
}

int			ft_check_cub(int ac, char **av, t_cub *cub)
{
	char	*map;

	if (ac == 1)
		ft_disp_error("Insert a map please !", cub);
	if (!(map = ft_strrchr(av[1], '.')))
		ft_disp_error("No extension !", cub);
	if (ft_strncmp(".cub", map, 5))
		ft_disp_error("Wrong extension, .cub is better :)", cub);
	cub->fd = open(av[1], O_RDONLY);
	if (!(cub->fd > 0))
	{
		ft_disp_error("No map found", cub);
		return (0);
	}
	return (1);
}
