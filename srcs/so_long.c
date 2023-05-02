/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:05:14 by hleung            #+#    #+#             */
/*   Updated: 2023/05/02 14:46:40 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	//t_slg	slg;

	if (argc == 2)
	{
		if (file_type_error(argv[1]) || !file_exist(argv[1]))
			return (1);
		map = make_map(argv[1]);
		if (!check_map_error(map))
			return (1);
		flood_fill(map);
		// for (int i = 0; i < map->row; i++)
		// 	printf("%s", map->map[i]);
		// printf("\n");
		// printf("%d\n", flood_fill(map));
		// for (int i = 0; i < map->row; i++)
		// 	printf("%s", map->map[i]);
		// if (!backtrack(map))
		// {
		// 	free_map(&map);
		// 	return (1);
		// }
		free_map(&map);
	// 	slg = launch_mlx(argv[1]);
	// 	return (free_everyting(&slg), 0);
	}
	else
		ft_putstr(ARG_ERROR);
	return (0);
}
