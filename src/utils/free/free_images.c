/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:45:17 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 09:44:54 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map->img.wall);
	mlx_destroy_image(game->mlx, game->map->img.floor);
	mlx_destroy_image(game->mlx, game->map->img.ceiling);
	mlx_destroy_image(game->mlx, game->map->img.pause);
	mlx_destroy_image(game->mlx, game->map->img.img);
}
