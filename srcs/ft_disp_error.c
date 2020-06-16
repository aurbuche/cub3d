/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:57:05 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/02 16:57:51 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

void         ft_disp_error(char *str)
{
    ft_putstr("\033[0;31m");
    printf("Error : %s\n", str);
    ft_putstr("\033[0m");
}