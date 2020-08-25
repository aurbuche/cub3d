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

static void			ft_search_wall(t_cub *cub)
{
	cub->maps.x = cub->pos.x;
	cub->maps.y = cub->pos.y;
}

void				ft_raycasting(t_cub *cub)
{
	int		x;

	x = 0;
	printf("%f/%f\n", cub->maps.x, cub->maps.y);
	printf("%d/%d", cub->res[0], cub->res[1]);
	while (x < cub->res[0])
	{
		ft_search_wall(cub);
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
