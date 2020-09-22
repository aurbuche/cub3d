/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:57:05 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/09/22 11:18:32 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void		ft_disp_error(char *str, t_cub *c)
{
	ft_putstr("\033[0;31m");
	ft_printf("Error : %s\n", str);
	ft_putstr("\033[0m");
	if (c->malloc == 1)
		ft_free_cub(c);
	exit(0);
}
