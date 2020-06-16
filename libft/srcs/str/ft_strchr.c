/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:13:16 by aurbuche          #+#    #+#             */
/*   Updated: 2020/06/11 10:18:04 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (c == '\0' && *str == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char*)str);
		}
		i++;
	}
	if (str[i] == c)
		return ((char*)str);
	return (0);
}
