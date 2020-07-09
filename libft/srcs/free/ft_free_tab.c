/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:14:23 by user42            #+#    #+#             */
/*   Updated: 2020/07/09 15:36:13 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char		**ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i++])
		free(tab[i]);
	free(tab);
	return (NULL);
}
