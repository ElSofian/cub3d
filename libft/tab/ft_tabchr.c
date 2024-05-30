/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:51:50 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 11:57:11 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_tabchr(char **tab, char *str)
{
	int		i;
	bool	present;

	i = 0;
	present = false;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], str, ft_strlen(str)))
			present = true;
		i++;
	}
	return (present);
}
