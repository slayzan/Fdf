/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:30:30 by humarque          #+#    #+#             */
/*   Updated: 2019/06/17 16:45:30 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			changeview(t_build *param)
{
	mlx_destroy_image(param->graph.mlx_ptr, param->graph.img.img_ptr);
	param->graph.img.img_ptr = mlx_new_image(param->graph.mlx_ptr,
	WIDTH, HEIGHT);
	if (param->move.proj == 0)
		find_mid_para(param);
	else
		find_mid_iso(param);
	view(param);
	mlx_put_image_to_window(param->graph.mlx_ptr, param->graph.mlx_window,
	param->graph.img.img_ptr, 0, 0);
}

static void		changecolor2(int keycode, t_build *param)
{
	if (keycode == 5)
	{
		if (param->move.color == 0xFF00FF)
			param->move.color = 0xFFFFFF;
		else if (param->move.color == 0xFFFFFF || param->move.color ==
		0x00FF00)
			param->move.color = 0x00FF00;
		else if (param->move.color != 0xFFFF00 && param->move.color != 0x00FFFF)
			param->move.color = param->move.color == 0xFF0000 ? 0xFFFF00 :
			0x00FFFF;
	}
	if (keycode == 15)
	{
		if (param->move.color == 0x00FFFF)
			param->move.color = 0xFFFFFF;
		else if (param->move.color == 0xFFFFFF || param->move.color == 0xFF0000)
			param->move.color = 0xFF0000;
		else if (param->move.color != 0xFFFF00 && param->move.color != 0xFF00FF)
			param->move.color = param->move.color == 0x00FF00 ? 0xFFFF00 :
			0xFF00FF;
	}
}

static void		changecolor(int keycode, t_build *param)
{
	if (keycode == 11)
	{
		if (param->move.color == 0xFFFF00)
			param->move.color = 0xFFFFFF;
		else if (param->move.color == 0xFFFFFF || param->move.color == 0x0000FF)
			param->move.color = 0x0000FF;
		else if (param->move.color != 0x00FFFF && param->move.color != 0xFF00FF)
			param->move.color = param->move.color == 0x00FF00 ? 0x00FFFF :
			0xFF00FF;
	}
	else
		changecolor2(keycode, param);
	changeview(param);
}

static void		zoom(int keycode, t_build *param)
{
	if (keycode == 78)
	{
		if (param->map.spc >= 3)
			param->map.spc -= 1;
		changeview(param);
	}
	else
	{
		if (((param->map.spc + 1) * param->map.taille * param->map.hauteur) <
		((HEIGHT * WIDTH) / 4))
			param->map.spc += 1;
		changeview(param);
	}
}

int				key_hook(int keycode, t_build *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 35)
	{
		param->move.proj = param->move.proj == 0 ? 1 : 0;
		changeview(param);
	}
	if (keycode == 11 || keycode == 5 || keycode == 15)
		changecolor(keycode, param);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (param->move.proj == 1)
			movemap_iso(keycode, param);
		else
			movemap_para(keycode, param);
	}
	if (keycode == 78 || keycode == 69)
		zoom(keycode, param);
	return (0);
}
