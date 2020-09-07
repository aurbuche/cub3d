/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:00:11 by user42            #+#    #+#             */
/*   Updated: 2020/09/07 17:04:17 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub3d.h"

void        ft_print_params(t_cub *c)
{
    ft_printf("NO: %s\n", c->no);
    ft_printf("SO: %s\n", c->so);
    ft_printf("EA: %s\n", c->ea);
    ft_printf("WE: %s\n", c->we);
    ft_printf("S: %s\n", c->s);
    ft_printf("R: %d %d\n", c->res[0], c->res[1]);
}