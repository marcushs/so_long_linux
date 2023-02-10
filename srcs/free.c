/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:58:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/23 10:45:37 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_message_exit(char *err)
{
	ft_putstr(err);
	exit(0);
}

void	free_prev_arr(void **arr, int i, char *err)
{
	i--;
	while (i >= 0)
	{
		free(((void **)*arr)[i]);
		((void **)*arr)[i] = NULL;
		i--;
	}
	free(*arr);
	*arr = NULL;
	print_message_exit(err);
}

void	free_2d_array(void **arr, int row)
{
	while (--row >= 0)
	{
		free(((void **)*arr)[row]);
		((void **)*arr)[row] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

void	free_map(t_map **map)
{
	free_2d_array((void **)&(*map)->map, (*map)->row);
	free((*map)->c);
	(*map)->c = NULL;
	free(*map);
	*map = NULL;
}

void	free_everyting(t_slg *slg)
{
	free_map(&slg->map);
	free(slg->p);
	slg->p = NULL;
	free(slg->e);
	slg->e = NULL;
}
