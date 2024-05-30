/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:50:04 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 12:26:44 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_around_space(t_game *game, int len_prev, int len_curr, int l)
{
	int	diff;
	int	k;

	diff = len_curr - len_prev;
	if (diff > 0)
	{
		k = len_prev;
		while (k < len_curr)
		{
			if (game->map->map[l][k] != '1' && game->map->map[l][k] != ' ')
				error_map("Map is invalid. Inconsistent wall structure.", game);
			k++;
		}
	}
	else if (diff < 0)
	{
		k = len_curr;
		while (k < len_prev)
		{
			if (game->map->map[l - 1][k] != '1'
				&& game->map->map[l - 1][k] != ' ')
				error_map("Map is invalid. Inconsistent wall structure.", game);
			k++;
		}
	}
}

static void	check_line_size(t_game *game)
{
	int	l;
	int	len_prev;
	int	len_curr;

	l = 1;
	len_prev = ft_strlen(game->map->map[0]);
	while (l < game->map->height)
	{
		len_curr = ft_strlen(game->map->map[l]);
		check_around_space(game, len_prev, len_curr, l);
		len_prev = len_curr;
		l++;
	}
}

static void	check_middle_walls(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map->height - 1)
	{
		j = skip(game->map->map[i], 32);
		if (game->map->map[i][j] != '1')
			error_map("Map is not surrounded by walls. (3)", game);
		while (game->map->map[i][j + 1])
		{
			if (game->map->map[i][j] != '1' && game->map->map[i][j] != '0'
				&& game->map->map[i][j] != 'N' && game->map->map[i][j] != 'S'
				&& game->map->map[i][j] != 'E' && game->map->map[i][j] != 'W'
				&& game->map->map[i][j] != ' ')
				error_map("Map contains non authorized character (2).", game);
			j++;
		}
		if (game->map->map[i][j] != '1')
			error_map("Map is not surrounded by walls. (4)", game);
		i++;
	}
}

static void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = skip(game->map->map[0], 32);
	while (game->map->map[0][i])
	{
		if (game->map->map[0][i] != '1' && game->map->map[0][i] != ' ')
			error_map("Map is not surrounded by walls. (1)", game);
		i++;
	}
	j = 0;
	while (game->map->map[game->map->height - 1][j])
	{
		if (game->map->map[game->map->height - 1][j] != '1'
			&& game->map->map[game->map->height - 1][j] != ' ')
			error_map("Map is not surrounded by walls. (2)", game);
		j++;
	}
	check_middle_walls(game);
}

void	check(t_game *game)
{
	int	len;

	if (!game->map->name)
		return ;
	len = ft_strlen(game->map->name);
	if (len < 4 || ft_strncmp(game->map->name + len - 4, ".cub", 4))
		error_map("The extension of the file is not .cub", game);
	check_instructions(game);
	if (!ft_tabchr(game->map->map, "NO") || !ft_tabchr(game->map->map, "SO")
		|| !ft_tabchr(game->map->map, "WE") || !ft_tabchr(game->map->map, "EA")
		|| !ft_tabchr(game->map->map, "F") || !ft_tabchr(game->map->map, "C"))
		error_map("Map is invalid, a texture is missing.", game);
	check_walls(game);
	check_line_size(game);
}
