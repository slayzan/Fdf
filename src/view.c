/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:05:29 by humarque          #+#    #+#             */
/*   Updated: 2019/05/29 18:32:07 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"
void	isometric(t_mlx *graph,int x, int y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = x;
	prev_y = y;

	x = (prev_x - prev_y) * cos(0.523599);
	y = -z + (prev_x  + prev_y) * sin(0.523599);
	graph->img.data[y * WIDTH + x] = 0xFFFFFF;
}

void	view(t_mlx *graph,t_build *param, int x, int y, int i)
{
	if (param->proj == 0)
		isometric(graph,x, y, param->map.grille[i]);
}