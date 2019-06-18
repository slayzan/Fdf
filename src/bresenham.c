/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:09:28 by kwatanab          #+#    #+#             */
/*   Updated: 2019/06/18 15:53:30 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		vertical(int *x, int *y, int *xy, t_build *param)
{
	int		i;
	int		e;

	i = 0;
	e = y[0] / 2;
	while (i < y[0])
	{
		xy[1] += y[1];
		e += x[0];
		if (e >= y[0])
		{
			e -= y[0];
			xy[0] += x[1];
		}
		param->graph.img.data[xy[1] * WIDTH + xy[0]] = param->move.color;
		i++;
	}
}

void		horizontal(int *x, int *y, int *xy, t_build *param)
{
	int		i;
	int		e;

	i = 0;
	e = x[0] / 2;
	while (i < x[0])
	{
		xy[0] += x[1];
		e += y[0];
		if (e >= x[0])
		{
			e -= x[0];
			xy[1] += y[1];
		}
		param->graph.img.data[xy[1] * WIDTH + xy[0]] = param->move.color;
		i++;
	}
}

void		bresenham(int *xy1, int x2, int y2, t_build *param)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = xy1[0];
	xy[1] = xy1[1];
	x[0] = abs(x2 - xy[0]);
	y[0] = abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	param->graph.img.data[xy[1] * WIDTH + xy[0]] = param->move.color;
	if (x[0] > y[0])
		horizontal(x, y, xy, param);
	else
		vertical(x, y, xy, param);
}
