/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:20:14 by kwatanab          #+#    #+#             */
/*   Updated: 2019/06/17 16:28:07 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		cadre1(t_build *param, int x)
{
	int		i;
	int		xy[2];

	i = 0;
	while (++i < param->map.spc + 1)
	{
		xy[0] = param->map.sx;
		xy[1] = param->map.sy;
		bresenham(xy, param->map.sx, param->map.sy - 1, param);
		param->map.sy--;
	}
}

void		cadre2(t_build *param, int x)
{
	int		i;
	int		xy[2];

	i = 0;
	while (++i < param->map.spc + 1)
	{
		param->map.sx++;
		if (x != param->map.taille - 1)
		{
			xy[0] = param->map.sx - 1;
			xy[1] = param->map.midy;
			bresenham(xy, param->map.sx, param->map.midy, param);
		}
	}
}
