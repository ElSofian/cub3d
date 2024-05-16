/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:11:28 by soelalou          #+#    #+#             */
/*   Updated: 2024/04/21 17:05:06 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*return_error(int err, char **tab)
{
	if (err == 1)
		ft_printf("An error occured while with allocating memory, ft_split.\n");
	else if (err == 2)
		ft_printf("An error has occured while allocate a tab in put_word().\n");
	if (tab)
		ft_freetab(tab);
	return (NULL);
}

char	**split(char *file, int height)
{
	int		fd;
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (return_error(1, NULL));
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("An error occured while opening the file.\n");
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s\n", line);
		free(line);
	}
	return (map);
}
