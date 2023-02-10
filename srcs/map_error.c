/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:08:50 by hleung            #+#    #+#             */
/*   Updated: 2023/01/23 10:40:28 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_type_error(char *file_path)
{
	char	*substr;

	substr = ft_substr(ft_strrchr(file_path, '.'), 0, 4);
	if (!substr)
	{
		ft_putstr(SUFF_ERROR);
		return (1);
	}
	if (ft_strncmp(substr, ".ber", 4))
	{
		ft_putstr(SUFF_ERROR);
		return (free(substr), substr = NULL, 1);
	}
	return (free(substr), substr = NULL, 0);
}

int	file_exist(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(FILE_ERROR);
		return (0);
	}
	close(fd);
	return (1);
}

static int	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (map->map[y][x] != '1' && \
			(y == 0 || y == map->row - 1 || x == 0 || x == map->col - 1))
			{
				ft_putstr(MAP_ERROR);
				return (free_map(&map), 0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	check_shape(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = count_cols(map->map[i]);
	i = 1;
	while (map->map[i])
	{
		if (len != count_cols(map->map[i]))
		{
			ft_putstr(MAP_ERROR);
			return (free_map(&map), 0);
		}
		i++;
	}
	return (1);
}

int	check_map_error(t_map *map)
{
	int		i;

	if (!check_shape(map) || !check_wall(map))
		return (0);
	i = 0;
	while (i < 256)
	{
		if (((i != 48 && i != 49 && i != 67 && i != 69 && i != 80) && \
		map->c[i]) || (map->c[67] < 1 || map->c[69] != 1 || map->c[80] != 1))
		{
			ft_putstr(MAP_ERROR);
			return (free_map(&map), 0);
		}
		i++;
	}
	return (1);
}
