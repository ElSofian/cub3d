/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:08:39 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 12:27:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_texture_path(char *line, t_game *game)
{
	char	**parts;

	parts = ft_split(line, ' ');
	(void)game;
	// if (!parts[1] || !parts[0])
	// 	error_map("Invalid texture path format.", game);
	// if (open(parts[1], O_RDONLY) < 0 || access(parts[1], F_OK) < 0)
	// 	error_map("Texture path does not exist.", game);
	free(parts);
}

static void	check_color_format(char *line, t_game *game)
{
	int		i;
	int		value;
	char	*color;
	char	**components;

	color = ft_strchr(line, ' ');
	if (!color)
		error_map("Invalid color format.", game);
	color++;
	components = ft_split(color, ',');
	if (!components[0] || !components[1] || !components[2])
		error_map("Invalid color format.", game);
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(components[i]);
		if (value < 0 || value > 255)
			error_map("Color value out of range.", game);
		i++;
	}
	free(components);
}

static void	check_instruction(char *line, t_game *game)
{
	printf("line: %s\n", line);
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		check_texture_path(line, game);
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		check_color_format(line, game);
	else
		error_map("Invalid map instruction.", game);
}

void	check_instructions(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		error_map("An error occured while opening the map file.", game);
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			error_map("Missing map instruction.", game);
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		check_instruction(line, game);
		i++;
	}
}
