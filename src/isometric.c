/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/06/11 18:34:21 by kwatanab         ###   ########.fr       */
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

	prev_x = x;
	prev_y = y;
	y = (prev_x + prev_y) * sin(0.523599) +
	param->map.midy + (-param->map.grille[i]);
	x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
	if (prev_y >= param->map.spc)
	{
		savey = prev_y - param->map.spc;
		if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT) &&
		(calx(prev_x, savey, param) > 0 && calx(prev_x, savey, param) < WIDTH)
		&& (caly(prev_x, savey, j, param) > 0 &&
		caly(prev_x, savey, j, param) < HEIGHT))
			bresenham(x, y, calx(prev_x, savey, param),
			caly(prev_x, savey, j, param), param);
	}
	if (prev_x != 0)
	{
		if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT) &&
		(param->map.sx > 0 && param->map.sx < WIDTH) &&
		(param->map.sy > 0 && param->map.sy < HEIGHT))
			bresenham(x, y, param->map.sx, param->map.sy, param);
	}
	param->map.sy = y;
	param->map.sx = x;
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
		param->graph.img.data[y * WIDTH + x] = param->move.color;
}
