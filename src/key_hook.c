/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:30:30 by humarque          #+#    #+#             */
/*   Updated: 2019/06/06 18:18:55 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		changeview(t_build *param)
{
	mlx_destroy_image(param->graph.mlx_ptr, param->graph.img.img_ptr);
	param->graph.img.img_ptr = mlx_new_image(param->graph.mlx_ptr,
		WIDTH, HEIGHT);
	find_mid(param);
	view(param);
	mlx_put_image_to_window(param->graph.mlx_ptr, param->graph.mlx_window,
	param->graph.img.img_ptr, 0, 0);
}

static void		changecolor2(int keycode, t_build *param)
{
	if (keycode == 5)
	{
		if (param->move.color == 0xFFFFFF || param->move.color == 0x00FF00)
			param->move.color = 0x00FF00;
		else
			param->move.color = param->move.color == 0xFF0000 ? 0xFFFF00 : 0x00FFFF;
		changeview(param);
	}
	if (keycode == 15)
	{
		if (param->move.color == 0xFFFFFF || param->move.color == 0xFF0000)
			param->move.color = 0xFF0000;
		else
			param->move.color = param->move.color == 0x00FF00 ? 0xFFFF00 : 0xFF00FF;
		changeview(param);
	}
}

static void		changecolor(int keycode, t_build *param)
{
	if (param->move.color == 0x00FFFF || param->move.color == 0xFF00FF ||
		param->move.color == 0xFFFF00)
	{
		param->move.color = 0xFFFFFF;
		changeview(param);
	}
	else if (keycode == 11)
	{
		if (param->move.color == 0xFFFFFF || param->move.color == 0x0000FF)
			param->move.color = 0x0000FF;
		else
			param->move.color = param->move.color == 0x00FF00 ? 0x00FFFF : 0xFF00FF;
		changeview(param);
	}
	else
		changecolor2(keycode, param);
}

static void		movemap(int keycode, t_build *param)
{
	if (keycode == 123)
	{
		printf("midx = %d\n", param->map.midx);
		changeview(param);
	}
}

static void	zoom(int keycode, t_build *param)
{	
	if (keycode == 78)
	{
		if (param->map.spc > 0)
			param->map.spc -= 1;
		changeview(param);
	}
	else
	{
		if (param->map.spc <= 80)
			param->map.spc += 1;
		changeview(param);
	}
}

int				key_hook(int keycode, t_build *param)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 34)
	{
		param->move.proj = param->move.proj == 0 ? 1 : 0;
		changeview(param);
	}
	if (keycode == 11 || keycode == 5 || keycode == 15)
		changecolor(keycode, param);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		movemap(keycode, param);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, param);
	return (0);
}


