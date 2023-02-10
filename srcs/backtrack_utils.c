/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:53 by hleung            #+#    #+#             */
/*   Updated: 2023/01/20 10:01:59 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	**allocate_2d_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = malloc(rows * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(int));
		if (!array[i])
			free_prev_arr((void **)&array, i, MALLOC_ERROR);
		ft_bzero(array[i], cols);
		i++;
	}
	return (array);
}	

static t_point	*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

int	**create_dir_array(void)
{
	int	**dir;

	dir = allocate_2d_array(4, 2);
	if (!dir)
	{
		ft_putstr(MALLOC_ERROR);
		exit(0);
	}
	dir[0][0] = -1;
	dir[0][1] = 0;
	dir[1][0] = 0;
	dir[1][1] = 1;
	dir[2][0] = 1;
	dir[2][1] = 0;
	dir[3][0] = 0;
	dir[3][1] = -1;
	return (dir);
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
