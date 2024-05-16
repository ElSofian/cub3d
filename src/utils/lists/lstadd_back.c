/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:19:06 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	lstadd_back(t_ghost **lst, t_ghost *new_lst)
{
	t_ghost	*tmp;

	if (!lst || !new_lst)
	{
		if (!lst)
			ft_printf("Argument lst is NULL in ft_lstadd_back() function.\n");
		if (!new_lst)
			ft_printf("Argument new_lst is NULL in lstadd_back() function.\n");
		return ;
	}
	tmp = NULL;
	tmp = lstlast(*lst);
	if (!tmp)
		*lst = new_lst;
	else
		tmp->next = new_lst;
}
