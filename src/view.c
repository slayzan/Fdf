/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/05/30 17:33:21 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"
/*void	bresen_iso(t_build *param, t_mlx *graph,int x, int y)
{
	int x;
	int y;
	int x2;
	int y2;

	x = ( * cos(0.523599) + param->map.midx;
	y = -param->map.grille[0] + 0 * sin(0.523599) + param->map.midy;
	x2 = 0;
	y2 = 0;
	bresenham(param->map.midx, param->map.midy, x, y, graph);
	printf("hello");
	

}*/
void	isometric(t_mlx *graph,int x, int y,t_build *param, int i)
{
	int prev_x;
	int prev_y;
	int a;
	prev_x = x;
	prev_y = y;

	a = 0;

	x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
	y = -param->map.grille[i] + (prev_x  + prev_y) * sin(0.523599) + param->map.midy;

	printf("%d\n", x);
	if (prev_x != 0)
	{	
		while (a != SPC_PIXEL)
		{
			bresenham(x, y, param->map.sx, param->map.sy, graph);
			a++;
		}
	}

	param->map.sy = y;
	param->map.sx = x;
	//graph->img.data[y * WIDTH + x] = 0xFFFFFF;
}

void	view(t_mlx *graph,t_build *param, int x, int y, int i)
{
	if (param->proj == 0)
		isometric(graph,x, y, param, i);
}
