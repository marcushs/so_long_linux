/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:48:54 by hleung            #+#    #+#             */
/*   Updated: 2023/05/02 16:21:22 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill_exit(t_map *map, t_point *end, int y, int x)
{
	if (x <= 0 || x >= map->col || y <= 0 || y >= map->row)
		return ;
	if (map->map[y][x] == '1' || map->map[y][x] == 's')
		return ;
	if (x == end->x && y == end->y)
	{
		map->c[69] = 0;
		ft_putstr_fd("Map solvable!\n", 1);
	}
	map->map[y][x] = 's';
	fill_exit(map, end, y - 1, x);
	fill_exit(map, end, y, x + 1);
	fill_exit(map, end, y + 1, x);
	fill_exit(map, end, y, x - 1);
}

static void	fill_collect(t_map *map, int y, int x, int *count)
{
	if (x <= 0 || x >= map->col || y <= 0 || y >= map->row)
		return ;
	if (map->map[y][x] == '1' || map->map[y][x] == '*' || map->map[y][x] == 'E')
		return ;
	if (map->map[y][x] == 'C')
		*count = *count + 1;
	map->map[y][x] = '*';
	fill_collect(map, y - 1, x, count);
	fill_collect(map, y, x + 1, count);
	fill_collect(map, y + 1, x, count);
	fill_collect(map, y, x - 1, count);
}

int	flood_fill(t_map *map)
{
	static int	count;
	t_point		*start;
	t_point		*end;
	t_point		*start_cpy;

	count = 0;
	start = get_point(map, 'P');
	end = get_point(map, 'E');
	start_cpy = get_point(map, 'P');
	for (int i = 0; i < map->row; i++)
		printf("%s", map->map[i]);
	printf("\n");
	//printf("%d\n", fill_collect(map, start->y, start->x , &count));
	fill_collect(map, start->y, start->x , &count);
	printf("%d\n", count);
	for (int i = 0; i < map->row; i++)
		printf("%s", map->map[i]);
	printf("\n");
	if (count == map->c[67])
	{
		fill_exit(map, end, start_cpy->y, start_cpy->x);
		if (map->c[69])
		{
			ft_putstr_fd("Map not solvable!\n", 1);
			return (0);
		}
		else
			return (1);
	}
	// if (!start || !end || !start_cpy)
	// 	return (free_nodes(&start, &end, &start_cpy, &dir), 0);
	return (0);
}
