/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:58:51 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 12:24:06 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/time.h>
# include <time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# ifndef PLAYER_NAME
#  define PLAYER_NAME "Rico"
# endif

# ifndef SIZE
#  define SIZE 32
# endif

# define ESCAPE 0xff1b
# define SPACE 0x0020
# define UP 0xff52
# define DOWN 0xff54
# define LEFT 0xff51
# define RIGHT 0xff53
# define W 0x0077
# define S 0x0073
# define A 0x0061
# define D 0x0064
# define R 0x0072

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	int		z;
	int		moves;
	char	direction;
	char	*name;
}	t_player;

typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	void	*addr;
	void	*wall;
	void	*floor;
	void	*ceiling;
	void	*pause;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		player[3];
	char	*path;
	char	*name;
	char	**map;
	t_img	img;
}	t_map;

typedef struct s_game
{
	bool		paused;
	bool		end;
	void		*mlx;
	void		*window;
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
}	t_game;

// Main

void	error_map(char *msg, t_game *game);
void	error(char *msg, t_game *game);
void	init(t_game *game, char **map_file);
void	open_window(t_game *game);
int		close_window(t_game *game);

// Moves

// Map

int		create_map(t_game *game);
void	render_image(t_game *game, void *img, int x, int y);
void	check(t_game *game);
void	check_instructions(t_game *game);

// Utils

int		open_file(t_game *game);
int		skip(char *line, int c);
void	free_images(t_game *game);
void	send_message(t_game *game, bool success);
void	pause_game(t_game *game);
char	**split(char *file, int height);
int		is_empty_line(char *line);

#endif