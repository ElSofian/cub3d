/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:39 by soelalou          #+#    #+#             */
/*   Updated: 2024/06/01 13:56:34 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		error("An error occured while initializing player", game);
		return ;
	}
	player->x = game->map->player[0];
	player->y = game->map->player[1];
	player->moves = 0;
	player->direction = 'N';
	player->name = ft_strdup(PLAYER_NAME);
	if (!player->name)
	{
		error("An error occured while initializing player name", game);
		return ;
	}
	game->player = player;
}

static int	init_image(t_game *game)
{
	// int	size;

	// size = SIZE;
	game->map->img.img = NULL;
	// game->map->img.img = mlx_new_image(game->mlx,
	// 		(game->map->width / game->map->height) * SIZE,
	// 		game->map->height * SIZE);
	// game->map->img.addr = mlx_get_data_addr(game->map->img.img,
	// 		&game->map->img.bits_per_pixel,
	// 		&game->map->img.line_length, &game->map->img.endian);
	return (0);
}

static void	init_textures(t_game *game)
{
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game->textures)
	{
		free(game);
		error("An error occured while initializing textures", NULL);
	}
	game->textures->north = NULL;
	game->textures->south = NULL;
	game->textures->west = NULL;
	game->textures->east = NULL;
	game->textures->floor = NULL;
	game->textures->ceiling = NULL;
}

static void	init_map(t_game *game, char **map_file)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		error("An error occured while initializing map", game);
	game->map->path = ft_strdup(*map_file);
	if (!game->map->path)
		error("An error occured while initializing map path", game);
	free(*map_file);
	game->map->name = ft_strdup(ft_strrchr(game->map->path, '/') + 1);
	if (!game->map->name)
		error("An error occured while initializing map name", game);
	create_map(game);
	for (int i = 0; game->map->map[i]; i++)
	{
		for (int j = 0; game->map->map[i][j]; j++)
			printf("%c", game->map->map[i][j]);
		printf("\n");
	}
	check(game);
	printf("\nNorth texture: %s\n", game->textures->north);
	printf("South texture: %s\n", game->textures->south);
	printf("West texture: %s\n", game->textures->west);
	printf("East texture: %s\n", game->textures->east);
	printf("Floor texture: %s\n", game->textures->floor);
	printf("Ceiling texture: %s\n", game->textures->ceiling);
	printf("\nMap is valid\n");
}

void	init(t_game *game, char **map_file)
{
	void	*mlx;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("An error occured while initializing game", NULL);
	mlx = mlx_init();
	if (!mlx)
	{
		free(game);
		error("An error occured while initializing mlx", NULL);
	}
	game->mlx = mlx;
	game->paused = false;
	init_textures(game);
	init_map(game, map_file);
	init_player(game);
	// open_window(game);
	init_image(game);
	// mlx_hook(game->window, 17, 0, close_window, game);
	// mlx_loop(game->mlx);
}
