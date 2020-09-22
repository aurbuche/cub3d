/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_level.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 09:08:09 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 12:07:27 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static char		**ft_select_level(t_cub *c)
{
	char		**next;

	next = (char **)malloc(sizeof(char *) * 2);
	next[0] = ft_strdup("./Cub3D");
	if (c->level == 1)
		next[1] = ft_strdup("level2.cub");
	else if (c->level == 2)
		next[1] = ft_strdup("level3.cub");
	return (next);
}

void			ft_next_level(t_cub *c)
{
	char		**next;
	
	if (!(c->level == 2))
	{
		c->level++;
		next = ft_select_level(c);
		mlx_destroy_window(c->mlx_ptr, c->mlx_win);
		ft_free_cub(c);
		ft_start(2, next, c->level);
	}
	c->end = 1;
}
