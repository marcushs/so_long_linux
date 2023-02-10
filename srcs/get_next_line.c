/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:27:36 by hleung            #+#    #+#             */
/*   Updated: 2023/01/17 17:18:19 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_after_line(char *stash, char *line)
{
	char	*new_stash;
	int		i;
	int		j;

	new_stash = (char *)ft_calloc((ft_strlen(stash) - ft_strlen(line) + 1), 1);
	if (!new_stash || !stash)
		return (free(stash), stash = NULL, NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == 0)
		return (free(stash), stash = NULL, free(new_stash), \
		new_stash = NULL, NULL);
	i++;
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	return (free(stash), stash = NULL, new_stash);
}

static char	*ft_get_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == 0)
		line = (char *)ft_calloc((i + 1), sizeof(char));
	else
		line = (char *)ft_calloc((i + 2), sizeof(char));
	if (!line || !stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] != 0)
		line[i] = '\n';
	return (line);
}

static char	*ft_reader(int fd, char *stash)
{
	int		rd_size;
	char	*buf;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	rd_size = 1;
	while (!ft_strchr_gnl(stash, '\n') && rd_size != 0)
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size == -1)
			return (free(buf), free(stash), buf = NULL, stash = NULL, NULL);
		buf[rd_size] = 0;
		stash = ft_strjoin_gnl(stash, buf);
	}
	return (free(buf), buf = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_reader(fd, stash);
	if (!stash || stash[0] == 0)
		return (free(stash), stash = NULL, NULL);
	line = ft_get_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_after_line(stash, line);
	return (line);
}
