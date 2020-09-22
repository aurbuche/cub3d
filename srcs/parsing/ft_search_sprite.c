/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 16:52:47 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void			ft_stack_sprite(t_cub *c)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < c->n_line - 1)
	{
		j = 0;
		while (j < c->map[i][j])
		{
			if (c->map[i][j] == '2')
			{
				c->sprites[k].pos.x = i + 0.5;
				c->sprites[k].pos.y = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void				ft_search_sprite(t_cub *c)
{
	size_t	i;
	int		j;

	i = 0;
	c->n_sprite = 0;
	while (i < c->n_line - 1)
	{
		j = 0;
		while (j < c->map[i][j])
		{
			if (c->map[i][j] == '2')
				c->n_sprite++;
			j++;
		}
		i++;
	}
	c->sprites = (t_sprite *)malloc(sizeof(t_sprite) * c->n_sprite);
	ft_stack_sprite(c);
	c->sp = 1;
}
