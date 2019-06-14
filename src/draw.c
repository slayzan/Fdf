/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:46:39 by humarque          #+#    #+#             */
/*   Updated: 2019/06/14 16:35:36 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		draw_iso(t_build *param)
{
	int		x;
	int		y;
	int		i;
	int		j;

	param->first = 0;
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (x < param->map.taille * param->map.spc ||
	y < param->map.hauteur * param->map.spc - param->map.spc)
	{
		if (x == param->map.taille * param->map.spc)
		{
			x = 0;
			y += param->map.spc;
			param->first = 1;
		}
		isometric(x, y, param, i, j);
		x += param->map.spc;
		i++;
		if (y >= 1)
			j++;
	}
}

static void		cadre(t_build *param, int function, int x)
{
	int		i;
	int		xy1[2];

	i = 0;
	if (function)
	{
		while (++i < param->map.spc + 1)
		{
			xy1[0] = param->map.sx;
			xy1[1] = param->map.sy;
			bresenham(xy1, param->map.sx, param->map.sy - 1, param);
			param->map.sy--;
		}
	}
	else
	{
		while (++i < param->map.spc + 1)
		{
			param->map.sx++;
			if (x != param->map.taille - 1)
			{
				xy1[0] = param->map.sx - 1;
				xy1[1] = param->map.midy;
				bresenham(xy1, param->map.sx, param->map.midy, param);
			}
		}
	}
}

static void		draw_para(t_build *param)
{
	int		x;
	int		i;
	int		y;
	int		first;

	i = 0;
	y = 0;
	first = 0;
	while (y < param->map.hauteur)
	{
		x = 0;
		while (x < param->map.taille)
		{
			param->graph.img.data[param->map.midy * WIDTH + param->map.sx] =
			param->move.color;
			if (first)
				cadre(param, 1, x);
			param->map.sy = param->map.midy;
			cadre(param, 0, x);
			x++;
		}
		param->map.midy = param->map.midy + param->map.spc;
		param->map.sy = param->map.midy;
		param->map.sx = param->map.midx;
		first = 1;
		y++;
		i++;
	}
}

void			view(t_build *param)
{
	if (param->move.proj == 1)
		draw_iso(param);
	if (param->move.proj == 0)
	{
		param->map.sx = param->map.midx;
		draw_para(param);
	}
}
