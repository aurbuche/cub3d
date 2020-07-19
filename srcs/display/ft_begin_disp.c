/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_disp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:10:49 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/18 14:27:03 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libcub3d.h"

int			unused_key(int key, t_data *data)
{
	if (key == K_ESCAPE)
		ft_close(data);
	if (key == K_W)
		data->move =  0;
	else if (key == K_S)
		data->move = 0;
	else if (key == K_A)
		data->move = 0;
	else if (key == K_D)
		data->move = 0;
	else if (key == K_SPACE)
		data->move = 0;
	return (1);
}

int			use_key(int key, t_data *data)
{
	if (key == K_ESCAPE)
		ft_close(data);
	if (key == K_W)
		data->move = 'w';
	else if (key == K_S)
		data->move = 's';
	else if (key == K_A)
		data->move = 'a';
	else if (key == K_D)
		data->move = 'd';
	else if (key == K_SPACE)
		data->move = ' ';
	return (1);
}

int			ft_begin_disp(t_cub *cub)
{
	t_data		*data;

	// ft_start_player_pos(cub);
	data = ft_init_data();
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, cub->res[0], cub->res[1], "Hello World")) == NULL)
		return (EXIT_FAILURE);
	mlx_key_hook(data->mlx_win, &use_key, data);
	mlx_key_hook(data->mlx_ptr, &unused_key, data);
	mlx_loop(data->mlx_ptr);
	return (EXIT_SUCCESS);
	return (1);
}
