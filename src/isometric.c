/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/06/14 16:37:04 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		calx(int prev_x, int prev_y, t_build *param)
{
	int x;

	x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
	return (x);
}

int		caly(int prev_x, int prev_y, int j, t_build *param)
{
	int y;

	y = -(param->map.grille[j]) + (prev_x + prev_y) *
	sin(0.523599) + param->map.midy;
	return (y);
}

void	isometric(int x, int y, t_build *param, int i, int j)
{
	int		prev_x;
	int		prev_y;
	int		savex;
	int		savey;
	int		xy1[2];

	prev_x = x;
	prev_y = y;
	y = (prev_x + prev_y) * sin(0.523599) +
	param->map.midy + (-param->map.grille[i]);
	x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
	if (prev_y >= param->map.spc)
	{
		savey = prev_y - param->map.spc;
		xy1[0] = x;
		xy1[1] = y;
		bresenham(xy1, calx(prev_x, savey, param),
		caly(prev_x, savey, j, param), param);
	}
	if (prev_x != 0)
	{
		xy1[0] = x;
		xy1[1] = y;
		bresenham(xy1, param->map.sx, param->map.sy, param);
	}
	param->map.sy = y;
	param->map.sx = x;
	param->graph.img.data[y * WIDTH + x] = param->move.color;
}
