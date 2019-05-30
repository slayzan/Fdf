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

void		vertical(int *x, int *y, int *xy)
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
		printf("Point = {%d; %d}\n", xy[0], xy[1]);
		i++;
	}
}

void		horizontal(int *x, int *y, int *xy)
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
		printf("Point = {%d; %d}\n", xy[0], xy[1]);
		i++;
	}
}

void		bresenham(int *tabxy, int x2, int y2)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = tabxy[0];
	xy[1] = tabxy[1];
	x[0] = abs(x2 - xy[0]);
	y[0] = abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	printf("Point = {%d; %d}\n", xy[0], xy[1]);
	if (x[0] > y[0])
		horizontal(x, y, xy);
	else
		vertical(x, y, xy);
}

// int main()
// {
// 	int tabxy[2] = {-6, 4};
// 	int x2 = 9;
// 	int y2 = -5;
// 	bresenham(tabxy, x2, y2);
// 	return (0);
// }
