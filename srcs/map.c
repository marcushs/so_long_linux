/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:16:24 by hleung            #+#    #+#             */
/*   Updated: 2023/05/04 17:38:01 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_cols(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int	count_lines(char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || line[0] == 0 || line[0] == '\n')
	{
		close(fd);
		ft_putstr_fd(MAP_ERROR, 1);
		return (free(line), line = NULL, 0);
	}
	if (line && line[0] != '\n')
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && line[0] != '\n')
			i++;
	}
	close(fd);
	return (free(line), line = NULL, i);
}

static int	*count_char(t_map *map)
{
	int	x;
	int	y;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 256);
	if (!arr)
	{
		free_map(&map);
		print_message_exit(MALLOC_ERROR);
	}
	ft_bzero(arr, sizeof(int) * 256);
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			arr[(int)map->map[y][x]]++;
			x++;
		}
		y++;
	}
	return (arr);
}

static char	**parse_map(char *file_path, int row)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
	{
		return (NULL);
		ft_printf(MALLOC_ERROR);
	}
	fd = open(file_path, O_RDONLY);
	map[0] = get_next_line(fd);
	i = 0;
	while (++i < row)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_prev_arr((void **)&map, i);
	}
	map[i] = 0;
	close(fd);
	return (map);
}

t_map	*make_map(char *file_path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		print_message_exit(MALLOC_ERROR);
	map->map = NULL;
	map->c = NULL;
	map->row = 0;
	map->col = 0;
	map->row = count_lines(file_path);
	if (!map->row)
		return (free_map(&map), NULL);
	map->map = parse_map(file_path, map->row);
	if (!map->map)
		return (free_map(&map), NULL);
	map->col = count_cols(map->map[map->row - 1]);
	map->c = count_char(map);
	return (map);
}
