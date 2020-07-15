/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:23:03 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/07/15 09:23:07 by aurelienbuc      ###   ########lyon.fr   */
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
