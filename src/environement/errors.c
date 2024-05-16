/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:19 by soelalou          #+#    #+#             */
/*   Updated: 2024/04/21 16:20:59 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game->map->path);
		free(game->map->name);
		free(game->map);
		free(game);
	}
	exit(EXIT_FAILURE);
}

void	error(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
		close_window(game);
	exit(EXIT_FAILURE);
}
