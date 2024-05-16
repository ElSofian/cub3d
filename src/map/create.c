/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:46:41 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/16 17:38:53 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static char	*append(t_game *game, char *res, char *line)
// {
// 	char	*new_res;
// 	char	*trimed_line;

// 	trimed_line = ft_strtrim(line, " \t\r\n");
// 	if (!trimed_line)
// 	{
// 		free(res);
// 		free(line);
// 		error_map("An error occured while creating map. (3)", game);
// 	}
// 	new_res = ft_strjoin(res, trimed_line);
// 	if (!new_res)
// 	{
// 		free(res);
// 		free(line);
// 		free(trimed_line);
// 		error_map("An error occured while creating map. (2)", game);
// 	}
// 	free(res);
// 	free(line);
// 	free(trimed_line);
// 	return (new_res);
// }

int	create_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open_file(game);
	if (!fd)
		error_map("An error occured while creating map. (0)", game);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 0)
			continue ;
		game->map->map[i] = ft_strdup(line);
		if (game->map->map[i][ft_strlen(game->map->map[i]) - 1] == '\n')
			game->map->map[i][ft_strlen(game->map->map[i]) - 1] = 0;
		if (!game->map->map[i])
			error_map("An error occured while creating map. (1)", game);
		free(line);
		i++;
	}
	game->map->height = i;
	return (close(fd), 0);
}
