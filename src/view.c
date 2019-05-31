/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/05/31 14:52:03 by humarque         ###   ########.fr       */
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

int		ft_calx(int prev_x, int prev_y, t_build *param)
{
	int x;

	x = (prev_x - prev_y) * -cos(0.523599) + param->map.midx;
	return (x);
}

int 	ft_caly(int prev_x, int prev_y, int i, t_build *param)
{
	int y;
	y = -param->map.grille[i] + (prev_x  + prev_y) * sin(0.523599) + param->map.midy;
	return (y);
}
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

	if(param->first == 1)
	{
		while (a != SPC_PIXEL)
		{
			bresenham(x,y, ft_calx(prev_x, prev_y, param), ft_caly(prev_x,prev_y,i,param), graph);
			a++;
		}
	}
	a = 0;
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
