/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:53 by hleung            #+#    #+#             */
/*   Updated: 2023/05/04 17:36:41 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_point	*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
	{
		ft_putstr_fd(MALLOC_ERROR, 1);
		return (NULL);
	}
	point->x = x;
	point->y = y;
	return (point);
}

t_point	*get_point(t_map *map, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		while (map->map[y][x] != 0 && map->map[y][x] != '\n')
		{
			if (map->map[y][x] == c)
				return (create_point(x, y));
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}
