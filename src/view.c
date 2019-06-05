/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/06/05 11:42:18 by humarque         ###   ########.fr       */
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
*/	
int             ft_calx(int prev_x, int prev_y, t_build *param)
{
	    int x;
		
		    x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
			    return (x);
}
int	ft_caly(int prev_x, int prev_y, int j, t_build *param)
{
	    int y;
		    y =  -(param->map.grille[j]) + ( prev_x  + prev_y) * sin(0.523599) + param->map.midy;
			return (y);
}
void	isometric1(t_mlx *graph,int x, int y,t_build *param, int i, int j)
{
	int prev_x;
	int prev_y;
	int savex;
	int savey;
	prev_x = x;
	prev_y = y;

	y =  (prev_x  + prev_y) * sin(0.523599) + param->map.midy + (-param->map.grille[i]);
	x = (prev_x - prev_y) * cos(0.523599) + param->map.midx;
	if (prev_y >= 30)
	{

			savey = prev_y - 30;
			bresenham(x, y, ft_calx(prev_x,savey,param), ft_caly(prev_x,savey,j,param), graph);

	}
	if (prev_x != 0)
		bresenham(x, y, param->map.sx, param->map.sy, graph);
	param->map.sy = y;
	param->map.sx = x;
	graph->img.data[y * WIDTH + x] = 0xFFFFFF;
}

void	view(t_mlx *graph,t_build *param, int x, int y, int i, int j)
{

	if (param->proj == 0)
	{

		isometric1(graph,x, y, param, i, j);
	}
}
