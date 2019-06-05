/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:46:39 by humarque          #+#    #+#             */
/*   Updated: 2019/06/05 11:35:32 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		draw_iso(t_mlx *graph, t_build *param)
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
	while (x < param->map.taille * SPC_PIXEL ||
		y < param->map.hauteur * SPC_PIXEL - 1)
	{
		if (x == param->map.taille * SPC_PIXEL)
		{
			x = 0;
			y += SPC_PIXEL;
			param->first = 1;
		}
		isometric(graph, x, y, param, i, j);
		x += SPC_PIXEL;
		i++;
		if (y >= 1)
			j++;
	}
}

static void		cadre(t_build *param, t_mlx *graph, int function, int x)
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

static void		draw_para(t_build *param, t_mlx *graph, int first, int y)
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
				cadre(param, graph, 1, x);
			param->map.sy = param->map.midy;
			cadre(param, graph, 0, x);
			x++;
		}
		param->map.midy = param->map.midy + SPC_PIXEL;
		param->map.sy = param->map.midy;
		first = 1;
		param->map.sx = param->map.midx;
		y++;
	}
}

void			view(t_mlx *graph, t_build *param, int y, int i)
{
	if (param->proj == 0)
		draw_iso(graph, param);
	if (param->proj == 1)
	{
		param->map.sx = param->map.midx;
		draw_para(param, graph, param->first - 1, y);
	}
}
