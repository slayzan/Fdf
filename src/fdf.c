/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:03:51 by humarque          #+#    #+#             */
/*   Updated: 2019/06/05 18:46:36 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		spc_finder(t_build *param)
{
	int spc;

	spc = 0;
	while ((spc * param->map.hauteur) < (HEIGHT - (HEIGHT / 2)) &&
	(spc * param->map.taille) < (WIDTH - (WIDTH / 2)))
		spc += 1;
	spc -= 1;
	param->map.spc = spc;
}

static void		find_mid(t_build *param)
{
	int x;
	int y;
	int j;

	x = 640;
	y = 360;
	j = param->map.hauteur / 2 - 1;
	while (j >= 0)
	{
		y -= param->map.spc;
		j--;
	}
	param->map.midx = x;
	param->map.midy = y;
}

static int		key_press(int keycode, t_build *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 34)
		param->proj = 0;
	if (keycode == 35)
		param->proj = 1;
	return (0);
}

void			init_window(t_build *param)
{
	t_mlx	graph;
	int		i;
	int		y;

	i = 0;
	y = 0;
	param->proj = 1;
	param->first = 1;
	graph.mlx_ptr = mlx_init();
	graph.mlx_window = mlx_new_window(graph.mlx_ptr, WIDTH, HEIGHT
		, param->name);
	graph.img.img_ptr = mlx_new_image(graph.mlx_ptr, WIDTH, HEIGHT);
	graph.img.data = (int *)mlx_get_data_addr(graph.img.img_ptr
		, &graph.img.bpp, &graph.img.size_l, &graph.img.endian);
	spc_finder(param);
	find_mid(param);
	view(&graph, param, y, i);
	mlx_hook(graph.mlx_window, 2, 0, key_press, param);
	mlx_put_image_to_window(graph.mlx_ptr, graph.mlx_window,
	graph.img.img_ptr, 0, 0);
	mlx_loop(graph.mlx_ptr);
}
