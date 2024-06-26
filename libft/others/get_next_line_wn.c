/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_wn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:30:22 by soelalou          #+#    #+#             */
/*   Updated: 2024/05/30 09:13:40 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*init(int fd, char *buf, char *save)
{
	int		readed;
	char	*tmp;

	readed = 1;
	while (readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		else if (readed == 0)
			break ;
		buf[readed] = '\0';
		if (!save)
			save = ft_strdup("");
		if (!save)
			return (NULL);
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*save;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	save = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*save == '\0' || !save)
	{
		free(save);
		save = NULL;
	}
	line[i + 1] = '\0';
	return (save);
}

char	*get_next_line_wn(int fd)
{
	char		*line;
	char		*buf;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = init(fd, buf, save);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	save = extract(line);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}
