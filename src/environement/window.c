/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/16 17:43:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->player->name);
	free(game->player);
	free(game->map->path);
	free(game->map->name);
	ft_freetab(game->map->map);
	free(game->map);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	open_window(t_game *game)
{
	printf("game->map->width: %d\n", game->map->width);
	printf("game->map->height: %d\n", game->map->height);
	printf("game->map->name: %s\n", game->map->name);
	game->window = mlx_new_window(game->mlx,
			(game->map->width / game->map->height) * SIZE,
			game->map->height * SIZE, game->map->name);
	if (!game->window)
		error("An error occured while creating window\n", game);
}
