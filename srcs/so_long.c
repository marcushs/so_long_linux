/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:05:14 by hleung            #+#    #+#             */
/*   Updated: 2023/01/23 10:49:26 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_slg	slg;

	if (argc == 2)
	{
		if (file_type_error(argv[1]) || !file_exist(argv[1]))
			return (1);
		map = make_map(argv[1]);
		if (!check_map_error(map))
			return (1);
		if (!backtrack(map))
		{
			free_map(&map);
			return (1);
		}
		free_map(&map);
		slg = launch_mlx(argv[1]);
		return (free_everyting(&slg), 0);
	}
	else
		ft_putstr(ARG_ERROR);
	return (0);
}
