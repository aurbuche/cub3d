/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/09/14 15:07:30 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void     ft_stack_sprite(t_cub *c)
{
	size_t      i;
	size_t      j;

	i = 0;
	while (i < c->res[0])
	{
		j = 0;
		while (j < c->res[1])
		{
			if (c->map[i][j] == '2')
				c->n_sprite++;
			j++;
		}
		i++;
	}
}

void            ft_search_sprite(t_cub *c)
{
	size_t      i;
	size_t      j;

	i = 0;
	while (i < c->res[0])
	{
		j = 0;
		while (j < c->res[1])
		{
			if (c->map[i][j] == '2')
				c->n_sprite++;
			j++;
		}
		i++;
	}
	c->sprites = (t_sprite *)malloc(sizeof(t_sprite) * c->n_sprite);
	ft_stack_sprite(c);
}