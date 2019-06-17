/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:46:39 by humarque          #+#    #+#             */
/*   Updated: 2019/06/17 16:32:35 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_build	*draw_iso2(t_build *param, int *x, int *y)
{
	*x = 0;
	*y += param->map.spc;
	param->first = 1;
	return (param);
}

static void		draw_iso(t_build *param)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		xy[2];

	param->first = 0;
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (x < param->map.taille * param->map.spc ||
	y < param->map.hauteur * param->map.spc - param->map.spc)
	{
		if (x == param->map.taille * param->map.spc)
			param = draw_iso2(param, &x, &y);
		xy[0] = x;
		xy[1] = y;
		isometric(xy, param, i, j);
		x += param->map.spc;
		i++;
		if (y >= 1)
			j++;
	}
}

static t_build	*draw_para2(t_build *param, int *first)
{
	param->map.midy = param->map.midy + param->map.spc;
	param->map.sy = param->map.midy;
	param->map.sx = param->map.midx;
	*first = 1;
	return (param);
}

static void		draw_para(t_build *param)
{
	int		x;
	int		i;
	int		y;
	int		first;

	i = 0;
	y = 0;
	first = 0;
	while (y < param->map.hauteur)
	{
		x = 0;
		while (x < param->map.taille)
		{
			param->graph.img.data[param->map.midy * WIDTH + param->map.sx] =
			param->move.color;
			if (first)
				cadre1(param, x);
			param->map.sy = param->map.midy;
			cadre2(param, x);
			x++;
		}
		param = draw_para2(param, &first);
		y++;
		i++;
	}
}

void			view(t_build *param)
{
	if (param->move.proj == 1)
		draw_iso(param);
	if (param->move.proj == 0)
	{
		param->map.sx = param->map.midx;
		draw_para(param);
	}
}
