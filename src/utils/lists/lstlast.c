/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:19:27 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ghost	*lstlast(t_ghost *lst)
{
	t_ghost	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
