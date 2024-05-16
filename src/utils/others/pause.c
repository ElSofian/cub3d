/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:53:23 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pause_game(t_game *game)
{
	int	size;
	int	screen_width;
	int	screen_height;

	size = SIZE;
	if (game->paused)
		game->paused = false;
	else
		game->paused = true;
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	render_image(game, game->map->img.pause, (screen_width / (size / 2)),
		screen_height / size);
}
