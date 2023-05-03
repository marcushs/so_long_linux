/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:46:16 by hleung            #+#    #+#             */
/*   Updated: 2023/05/03 15:50:08 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_texture_path(t_slg *slg, int x, int y, char c)
{
	if (c == '1' && ((y == 0 || y == slg->map->row - 1) || \
	(x == 0 || x == slg->map->col - 1)))
		return ("assets/imgs/rock.xpm");
	else if (c == '1')
		return ("assets/imgs/tree.xpm");
	else if (c == 'E')
		return ("assets/imgs/temple_covered.xpm");
	else if (c == 'P')
		return ("assets/imgs/samurai.xpm");
	else if (c == 'C')
		return ("assets/imgs/sushi.xpm");
	else
		return ("assets/imgs/background.xpm");
}

void	render_other(t_slg slg, char c)
{
	int		img_w;
	int		img_h;
	char	*rp;

	if (c == 'P')
		rp = "assets/imgs/samurai.xpm";
	if (c == '0')
		rp = "assets/imgs/background.xpm";
	slg.img = mlx_xpm_file_to_image(slg.mlx, rp, &img_w, &img_h);
	mlx_put_image_to_window(slg.mlx, slg.win, slg.img, \
	slg.p->x * 64, slg.p->y * 64);
	mlx_destroy_image(slg.mlx, slg.img);
}

void	render_temple(t_slg slg)
{
	int		img_w;
	int		img_h;
	char	*rp;

	rp = "assets/imgs/background.xpm";
	slg.img = mlx_xpm_file_to_image(slg.mlx, rp, &img_w, &img_h);
	mlx_put_image_to_window(slg.mlx, slg.win, slg.img, \
	slg.e->x * 64, slg.e->y * 64);
	mlx_destroy_image(slg.mlx, slg.img);
	rp = "assets/imgs/temple.xpm";
	slg.img = mlx_xpm_file_to_image(slg.mlx, rp, &img_w, &img_h);
	mlx_put_image_to_window(slg.mlx, slg.win, slg.img, \
	slg.e->x * 64, slg.e->y * 64);
	mlx_destroy_image(slg.mlx, slg.img);
}

void	render_map(t_slg slg)
{
	int		img_w;
	int		img_h;
	char	*rp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (slg.map->map[y])
	{
		while (slg.map->map[y][x])
		{
			rp = get_texture_path(&slg, x, y, slg.map->map[y][x]);
			slg.img = mlx_xpm_file_to_image(slg.mlx, rp, &img_w, &img_h);
			mlx_put_image_to_window(slg.mlx, slg.win, slg.img, x * 64, y * 64);
			mlx_destroy_image(slg.mlx, slg.img);
			x++;
		}
		x = 0;
		y++;
	}
}

t_slg	launch_mlx(char *file_path)
{
	t_slg	slg;

	slg.mlx = mlx_init();
	slg.map = make_map(file_path);
	slg.p = get_point(slg.map, 'P');
	slg.e = get_point(slg.map, 'E');
	if (!slg.p || !slg.e)
	{
		free_map(&slg.map);
		free(slg.p);
		slg.p = NULL;
		free(slg.e);
		slg.e = NULL;
		print_message_exit(PARSE_ERROR);
	}
	slg.win = mlx_new_window(slg.mlx, slg.map->col * 64, \
	slg.map->row * 64, "so_long");
	slg.img = NULL;
	slg.count = 0;
	slg.steps = 0;
	render_map(slg);
	mlx_key_hook(slg.win, event_listener, &slg);
	mlx_hook(slg.win, 17, 0, exit_prog, &slg);
	mlx_loop(slg.mlx);
	return (slg);
}
