/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:03:51 by humarque          #+#    #+#             */
/*   Updated: 2019/05/31 18:33:50 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		find_mid(t_build *param)
{
	param->map.midx = (WIDTH / 2) - ((param->map.taille / 2) * SPC_PIXEL - 1);
	param->map.midy = (HEIGHT / 2) - ((param->map.hauteur / 2) * SPC_PIXEL - 1);
}

static int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	/*if (keycode == 34)
	{
		make_draw(param);
	}*/
	return (0);
}

static void		ft_cadre(t_build *param, t_mlx *graph, int function, int x)
{
	int		i;

	i = -1;
	if (function)
	{
		while (++i < SPC_PIXEL)
		{
			bresenham(param->map.sx, param->map.sy,
					param->map.sx, param->map.sy - 1, graph);
			param->map.sy--;
		}
	}
	else
	{
		while (++i < SPC_PIXEL)
		{
			param->map.sx++;
			if (x != param->map.taille - 1)
				bresenham(param->map.sx - 1, param->map.midy,
						param->map.sx, param->map.midy, graph);
		}
	}
}

static void		ft_draw(t_build *param, t_mlx *graph, int first, int y)
{
	int		x;
	int		i;

	i = 0;
	while (y < param->map.hauteur)
	{
		x = 0;
		while (x < param->map.taille)
		{
			graph->img.data[param->map.midy * WIDTH + param->map.sx] = 0xFFFFFF;
			if (first)
				ft_cadre(param, graph, 1, x);
			param->map.sy = param->map.midy;
			ft_cadre(param, graph, 0, x);
			x++;
		}
		param->map.midy = param->map.midy + SPC_PIXEL;
		param->map.sy = param->map.midy;
		first = 1;
		param->map.sx = param->map.midx;
		y++;
	}
}

void			init_window(t_build *param)
{
	t_mlx	graph;
	int		i;
	int		y;

	i = 0;
	y = 0;
	param->proj = 0;
	param->first = 1;
	graph.mlx_ptr = mlx_init();
	graph.mlx_window = mlx_new_window(graph.mlx_ptr, WIDTH, HEIGHT
		, param->name);
	graph.img.img_ptr = mlx_new_image(graph.mlx_ptr, WIDTH, HEIGHT);
	graph.img.data = (int *)mlx_get_data_addr(graph.img.img_ptr
		, &graph.img.bpp, &graph.img.size_l, &graph.img.endian);
	find_mid(param);
	//param->map.sx = param->map.midx;
	//ft_draw(param, &graph, param->first, y);
	draw(&graph,param);
	mlx_hook(graph.mlx_window, 2, 0, key_press, (void*)0);
	mlx_put_image_to_window(graph.mlx_ptr, graph.mlx_window
			, graph.img.img_ptr, 0, 0);
	mlx_loop(graph.mlx_ptr);
}
