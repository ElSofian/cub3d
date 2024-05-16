/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:54:40 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:14:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(t_game *game)
{
	int		fd;
	int		ret;

	if (!game->map->path)
		error_map("Map file path is NULL in open_file() function.", game);
	fd = open(game->map->path, O_RDONLY);
	ret = access(game->map->path, R_OK);
	if (fd < 0 || ret < 0)
	{
		close(fd);
		error_map("Map file not found, or not readable.", game);
	}
	return (fd);
}
