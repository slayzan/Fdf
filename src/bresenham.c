/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:09:28 by kwatanab          #+#    #+#             */
/*   Updated: 2019/05/22 17:09:50 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		vertical(int *x, int *y, int *xy, t_mlx *graph)
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
		graph->img.data[xy[1] * WIDTH + xy[0]] = 0xFFFFFF;
		i++;
	}
}

void		horizontal(int *x, int *y, int *xy, t_mlx *graph)
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
		graph->img.data[xy[1] * WIDTH + xy[0]] = 0xFFFFFF;
		i++;
	}
}

void		bresenham(int x1, int y1, int x2, int y2, t_mlx *graph)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = x1;
	xy[1] = y1;
	x[0] = abs(x2 - xy[0]);
	y[0] = abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	graph->img.data[xy[1] * WIDTH + xy[0]] = 0xFFFFFF;
	if (x[0] > y[0])
		horizontal(x, y, xy, graph);
	else
		vertical(x, y, xy, graph);
}

// int main()
// {
// 	int tabxy[2] = {-6, 4};
// 	int x2 = 9;
// 	int y2 = -5;
// 	bresenham(tabxy, x2, y2);
// 	return (0);
// }
