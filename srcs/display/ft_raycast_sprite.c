/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:51:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/14 13:02:55 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_raycast_sprite(t_cub *c)
{
	int		i;

	i = 0;
	free(c->sprite);
	ft_set_sprite(c);
	ft_sort_sprite(c);
}