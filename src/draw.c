/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:46:39 by humarque          #+#    #+#             */
/*   Updated: 2019/06/18 17:59:00 by humarque         ###   ########.fr       */
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

void			parra(t_build *param, int x, int y)
{
	int tabxy[2];
	int x2;
	int y2;

	x2 = x * param->map.spc;
	y2 = y * param->map.spc;
	tabxy[0] = param->map.midx + x2 + param->map.grille[x +
	(param->map.taille * y)] * -2;
	tabxy[1] = param->map.midy + y2 + param->map.grille[x +
	(param->map.taille * y)] * -2;
	if (x2 / param->map.spc < param->map.taille - 1)
		bresenham(tabxy, param->map.midx + (x2 + param->map.spc)
	+ param->map.grille[x + 1 + (param->map.taille * y)] * -2,
	param->map.midy + y2 +
	param->map.grille[x + 1 + (param->map.taille * y)] * -2, param);
	if (y2 / param->map.spc < param->map.hauteur - 1)
		bresenham(tabxy, param->map.midx + x2 + param->map.grille
			[x + (param->map.taille * (y + 1))] * -2,
			param->map.midy + (y2 + param->map.spc)
			+ param->map.grille[x + (param->map.taille
			* (y + 1))] * -2, param);
}

void			draw_para(t_build *param)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (x < param->map.taille ||
	y < param->map.hauteur - 1)
	{
		if (x == param->map.taille)
		{
			x = 0;
			y++;
		}
		parra(param, x, y);
		x++;
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
