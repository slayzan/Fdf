/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:03:51 by humarque          #+#    #+#             */
/*   Updated: 2019/06/06 18:20:25 by kwatanab         ###   ########.fr       */
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

void			find_mid(t_build *param)
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

void			init_window(t_build *param)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	param->move.proj = 0;
	param->move.color = 0xFFFFFF;
	param->first = 1;
	param->graph.mlx_ptr = mlx_init();
	param->graph.mlx_window = mlx_new_window(param->graph.mlx_ptr, WIDTH, HEIGHT
	, param->name);
	param->graph.img.img_ptr = mlx_new_image(param->graph.mlx_ptr, WIDTH, HEIGHT);
	param->graph.img.data = (int *)mlx_get_data_addr(param->graph.img.img_ptr
	, &param->graph.img.bpp, &param->graph.img.size_l, &param->graph.img.endian);
	spc_finder(param);
	find_mid(param);
	view(param);
	mlx_hook(param->graph.mlx_window, 2, 0, key_hook, param);
	mlx_put_image_to_window(param->graph.mlx_ptr, param->graph.mlx_window,
	param->graph.img.img_ptr, 0, 0);
	mlx_loop(param->graph.mlx_ptr);
}
