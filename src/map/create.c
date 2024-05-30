/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:46:41 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 09:48:18 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int count_lines(const char *file_path)
{
    int		fd;
    int		count;
    char	*line;

	count = 0;
	line = NULL;
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return (-1);
    while (1)
    {
		line = get_next_line(fd);
		if (!line)
			break ;
        count++;
        free(line);
    }
    close(fd);
    return (count);
}

static int is_config_line(t_game *game, char *line)
{
    char	*trimmed_line;

    trimmed_line = ft_strtrim(line, " \t\n\r\v\f");
    if (!trimmed_line)
        error_map("An error occured while trimming config line.", game);
    if (ft_strncmp(trimmed_line, "NO ", 3) == 0)
        game->textures->north = ft_strdup(trimmed_line + 3);
    else if (ft_strncmp(trimmed_line, "SO ", 3) == 0)
        game->textures->south = ft_strdup(trimmed_line + 3);
    else if (ft_strncmp(trimmed_line, "WE ", 3) == 0)
        game->textures->west = ft_strdup(trimmed_line + 3);
    else if (ft_strncmp(trimmed_line, "EA ", 3) == 0)
        game->textures->east = ft_strdup(trimmed_line + 3);
    else if (ft_strncmp(trimmed_line, "F ", 2) == 0)
        game->textures->floor = ft_strdup(trimmed_line + 2);
    else if (ft_strncmp(trimmed_line, "C ", 2) == 0)
        game->textures->ceiling = ft_strdup(trimmed_line + 2);
    else
        return (free(trimmed_line), 0);
    return (free(trimmed_line), 1);
}

static int is_empty_line(char *line)
{
    while (*line)
    {
        if (!ft_isspace(*line))
            return (0);
        line++;
    }
    return (1);
}

int	create_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open_file(game);
	if (!fd)
		error_map("An error occured while creating map. (0)", game);
	game->map->map = (char **)malloc(sizeof(char *) * (count_lines(game->map->path) + 1));
	if (!game->map->map)
		error_map("Failed to allocate memory for map", game);
	i = 0;
	while (1)
	{
		line = get_next_line_wn(fd);
		if (!line)
			break ;
		if (is_empty_line(line) || is_config_line(game, line))
        {
            free(line);
            continue ;
        }
		game->map->map[i] = ft_strdup(line);
		if (!game->map->map[i])
			error_map("An error occured while creating map. (1)", game);
		free(line);
		i++;
	}
	game->map->map[i] = NULL;
	game->map->height = i;
	return (close(fd), 0);
}
