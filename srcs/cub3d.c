/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:25:11 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/15 09:45:31 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

int			ft_start(int ac, char **av, t_cub *cub)
{
	char		*line;

	line = NULL;
	if (!(ft_check_cub(ac, av, cub)))
		return (-1);
	ft_parse(line, cub);
	close(cub->fd);
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
	ft_delete(&cub->ea);
	ft_delete(&cub->no);
	ft_delete(&cub->so);
	ft_delete(&cub->we);
	ft_delete(&cub->s);
}

int			main(int ac, char **av)
{
	t_cub		*cub;

	cub = ft_init_cub();
	ft_start(ac, av, cub);
	ft_begin_disp(cub);
	ft_free_cub(cub);
	free(cub);
}
