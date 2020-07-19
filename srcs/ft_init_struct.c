/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:01 by user42            #+#    #+#             */
/*   Updated: 2020/07/17 21:10:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcub3d.h"

t_data        *ft_init_data()
{
    t_data *data;

    if (!(data = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    data->move = 0;
    return (data);
}