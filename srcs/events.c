/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:05:02 by hleung            #+#    #+#             */
/*   Updated: 2023/05/03 15:51:46 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	event_listener(int kc, t_slg *slg)
{
	if (slg->count != slg->map->c[67])
		move_player_close(kc, slg);
	else
		move_player_open(kc, slg);
	if (kc == XK_Escape || ((slg->p->y == slg->e->y && slg->p->x == slg->e->x) \
	&& slg->count == slg->map->c[67]))
	{
		mlx_destroy_window(slg->mlx, slg->win);
		mlx_destroy_display(slg->mlx);
		free_everyting(slg);
		exit(0);
	}
	return (0);
}

int	exit_prog(t_slg *slg)
{
	mlx_destroy_window(slg->mlx, slg->win);
	mlx_destroy_display(slg->mlx);
	free_everyting(slg);
	exit(0);
	return (0);
}

void	move_player_close(int kc, t_slg *slg)
{
	if (kc == XK_w && slg->map->map[slg->p->y - 1][slg->p->x] != '1' && \
		slg->map->map[slg->p->y - 1][slg->p->x] != 'E')
		move_up(slg);
	else if (kc == XK_d && slg->map->map[slg->p->y][slg->p->x + 1] != '1' && \
			slg->map->map[slg->p->y][slg->p->x + 1] != 'E')
		move_right(slg);
	else if (kc == XK_s && slg->map->map[slg->p->y + 1][slg->p->x] != '1' && \
			slg->map->map[slg->p->y + 1][slg->p->x] != 'E')
		move_down(slg);
	else if (kc == XK_a && slg->map->map[slg->p->y][slg->p->x - 1] != '1' && \
			slg->map->map[slg->p->y][slg->p->x - 1] != 'E')
		move_left(slg);
}

void	move_player_open(int kc, t_slg *slg)
{
	if (kc == XK_w && slg->map->map[slg->p->y - 1][slg->p->x] != '1')
		move_up(slg);
	else if (kc == XK_d && slg->map->map[slg->p->y][slg->p->x + 1] != '1')
		move_right(slg);
	else if (kc == XK_s && slg->map->map[slg->p->y + 1][slg->p->x] != '1')
		move_down(slg);
	else if (kc == XK_a && slg->map->map[slg->p->y][slg->p->x - 1] != '1')
		move_left(slg);
}
