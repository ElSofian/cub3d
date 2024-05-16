/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:40:57 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_message(t_game *game, bool success)
{
	if (success)
		ft_printf("Congrats %s! You won in %d moves !\n",
			game->player->name, game->player->moves);
	else
		ft_printf("You have been killed by a ghost (with %d moves) !\n",
			game->player->moves);
}
