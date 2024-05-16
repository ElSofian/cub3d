/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occ_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 03:20:19 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:22:54 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_occ_tab(char **tab, char c)
{
	int	i;
	int	j;
	int	occ;

	i = 0;
	occ = 0;
	if (!tab || !c)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				occ++;
			j++;
		}
		i++;
	}
	return (occ);
}