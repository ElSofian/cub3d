/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:21:43 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}
