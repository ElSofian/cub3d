/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:50:04 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/16 18:09:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_middle_walls(t_game *game)
{
	int		i;
	int		j;

	i = 1;
	while (i < game->map->height - 1)
	{
		j = 0 + skip(game->map->map[i], 32);
		if (game->map->map[i][j] != '1')
			error_map("Map is not surrounded by walls. (3)", game);
		j++;
		while (game->map->map[i][j + 1])
		{
			if (game->map->map[i][j] != '1' && game->map->map[i][j] != '0'
				&& game->map->map[i][j] != 'N' && game->map->map[i][j] != 'S'
					&& game->map->map[i][j] != 'E')
				error_map("Map contains non authorized character (2).", game);
			j++;
		}
		if (game->map->map[i][j] != '1')
			error_map("Map is not surrounded by walls. (4)", game);
		i++;
	}
}

static void check_line_size(t_game *game)
{
	int diff;
	int	l;

	l = 1;
	while (l < game->map->height)
	{
		diff = ft_strlen(game->map->map[l]) - ft_strlen(game->map->map[l - 1]);
		if (diff > 1 || diff < -1)
		{
			if (diff > 0 && game->map->map[l][diff - 1] != '1')
				error_map("Map is invalid. Inconsistent wall structure.", game);
			else if (diff < 0 && game->map->map[l - 1][-diff - 1] != '1')
				error_map("Map is invalid. Inconsistent wall structure.", game);
		}
		l++;
	}
}

static void	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	ceiling;

	ceiling = 0;
	i = skip(game->map->map[ceiling], 32);
	if (!game->map->map[ceiling][i])
		error_map("Map is not surrounded by walls. (0)", game);
	while (game->map->map[ceiling][i])
	{
		if (game->map->map[ceiling][i] != '1')
			error_map("Map is not surrounded by walls. (1)", game);
		i++;
	}
	i = game->map->height - 1;
	j = 0;
	while (game->map->map[i][j])
	{
		if (game->map->map[i][j] != '1')
			error_map("Map is not surrounded by walls. (2)", game);
		j++;
	}
	check_middle_walls(game);
}

static void	check_over_and_missing(t_game *game)
{
	if (ft_occ_tab(game->map->map, 'N') > 1
		|| ft_occ_tab(game->map->map, 'S') > 1
		|| ft_occ_tab(game->map->map, 'E') > 1
		|| ft_occ_tab(game->map->map, 'W') > 1)
		error_map("Map contains more than one player.", game);
	else if (ft_occ_tab(game->map->map, 'N') == 0
		&& ft_occ_tab(game->map->map, 'S') == 0
		&& ft_occ_tab(game->map->map, 'E') == 0
		&& ft_occ_tab(game->map->map, 'W') == 0)
		error_map("Map doesn't contains a player.", game);
	else if (ft_occ_tab(game->map->map, '0') < 1)
		error_map("Map doesn't contains empty space.", game);
}


void	check(t_game *game)
{
	int	len;

	if (!game->map->name)
		return ;
	len = ft_strlen(game->map->name);
	if (len < 4 || ft_strncmp(game->map->name + len - 4, ".cub", 4))
		error_map("The extension of the file is not .cub", game);
	
	check_walls(game);
	check_line_size(game);
}
