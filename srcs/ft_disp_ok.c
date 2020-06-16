/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:08:39 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/16 09:12:41 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void            ft_disp_ok(char *line)
{
    ft_printf("_______________\n\n");
	ft_printf("%s\n", line);
    ft_printf("_______________\n\n");
}