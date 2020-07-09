/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:14:23 by user42            #+#    #+#             */
/*   Updated: 2020/07/09 15:36:13 by aurelienbuc      ###   ########lyon.fr   */
=======
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:14:23 by user42            #+#    #+#             */
/*   Updated: 2020/07/07 20:14:19 by user42           ###   ########lyon.fr   */
>>>>>>> 500e73ffb67452834761764007e1def31743261b
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
