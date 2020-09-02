/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:30:00 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 16:49:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

static void			ft_setup(t_cub *c, int x)
{
	c->camerax = 2 * x / (double)c->res[0] - 1;
	c->dir_ray.x = c->dir.x + c->plane.x * c->camerax;
	c->dir_ray.y = c->dir.y + c->plane.y * c->camerax;
	c->maps.x = (int)c->pos.x;
	c->maps.y = (int)c->pos.y;
	c->delta_dist.x = fabs(1 /c->ray_dist.x);
	c->delta_dist.y = fabs(1 /c->ray_dist.y);
	c->ishit = 0;
}

static void			ft_search_wall(t_cub *c)
{
	if (c->dir_ray.x < 0)
	{
		c->step.x = -1;
		c->side_dist.x = (c->pos.x - c->maps.x) * c->delta_dist.x;
	}
	else
	{
		c->step.x = 1;
		c->side_dist.x = (c->maps.x +1.0 - c->pos.x) * c->delta_dist.x;
	}
	if (c->dir_ray.y < 0)
	{
		c->step.y = -1;
		c->side_dist.y = (c->pos.y - c->maps.y) * c->delta_dist.y;
	}
	else
	{
		c->step.y = 1;
		c->side_dist.y = (c->maps.y +1.0 - c->pos.y) * c->delta_dist.y;
	}
}

static void			DDA(t_cub *c)
{
	while(!c->ishit)
	{
		if (c->side_dist.x < c->side_dist.y)
		{
			c->side_dist.x += c->delta_dist.x;
			c->maps.x += c->step.x;
			c->side = 0;
		}
		else
		{
			c->side_dist.y += c->delta_dist.y;
			c->maps.y += c->step.y;
			c->side = 1;
		}
		if (c->map[c->maps.x][c->maps.y] == '1')
			c->ishit = 1;
	}
}

void				ft_raycasting(t_cub *c)
{
	int		x;

	x = 0;
	// printf("%f/%f\n", c->maps.x, c->maps.y);
	// printf("%d/%d", c->res[0], c->res[1]);
	while (x < c->res[0])
	{
		ft_setup(c, x);
		ft_search_wall(c);
		DDA(c);
		ft_(c);
		x++;
	}

}


/***************ALGORITHME***************/
/*Boucle de 0 a res[0] - 1*/
	/*lancer rayon pour trouver un mur ou un sprite*/
	//->/*on fait avancer tant que aucun mur n'a ete trouve*/
	//->/*on enregistre la distance parcourue*/

	/*pour optimiser la recherche on va uniquement verifier
	au niveau des intersections verticales et horizontales*/
	/*on fait donc appel au DDA qui est un algorithme mathematique*/

	/**Detection horizontale***/
	//-> /*Ya est une constante, longueur de la case*/
	//->/*trouver le premier point d'intersection sur X*/
	//->/*trouver le multiplicateur Ya (Ya: + rayon oriente vers le bas et - oriente vers le haut*/
	//->/*trouver la distance entre deux points d'intersection (X2 - X1)*/

	/***Detection verticale***/
	//-> /*Xa est une constante, longueur de la case*/
	//->/*trouver le point d'intersection Y*/
	//->/*trouver le multiplicateur Xa*/
	//->/*trouver la distance entre deux point d'intersection Y*/

	/**Trouver la distance**/
	//->/*verifier entre les distance la plus courte des deux distances*/
	//->/*D = racine carree (diffX2 + diffY2)*/
	//->/*exemple*/
		/*distance entre mur et camera*/
	//->/*dist = (a * posX + b * posY + c) / (a * sin(angle du rayon) + b * cos(angle du rayon))*/
