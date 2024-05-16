/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:07:08 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/26 03:31:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*map_file;
	t_game	*game;

	if (ac != 2)
		error("Wrong number of arguments.", NULL);
	map_file = ft_strdup(av[1]);
	if (!map_file)
		error("An error occured while creating map file path.", NULL);
	fd = open(map_file, O_RDONLY);
	ret = access(map_file, R_OK);
	if (fd < 0 || ret < 0)
		return (free(map_file), close(fd),
			error("Map file not found, or not readable.", NULL), 1);
	close(fd);
	game = NULL;
	init(game, &map_file);
	return (0);
}
