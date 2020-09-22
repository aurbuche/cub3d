/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:22:25 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 11:14:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

int			ft_close(t_cub *cub)
{
	if (cub->fd != -1)
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	ft_free_cub(cub);
	exit(0);
}