/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_disp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:10:49 by aurelienbuc       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/07/09 14:04:40 by aurelienbuc      ###   ########lyon.fr   */
=======
/*   Updated: 2020/07/08 14:08:06 by user42           ###   ########lyon.fr   */
>>>>>>> 500e73ffb67452834761764007e1def31743261b
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			ft_begin_disp(t_cub *cub)
{
<<<<<<< HEAD
	t_data			data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, cub->res[0], cub->res[1], "Hello World")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
=======
	if (())
	return (1);
>>>>>>> 500e73ffb67452834761764007e1def31743261b
}