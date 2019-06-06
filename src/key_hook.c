/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:30:30 by humarque          #+#    #+#             */
/*   Updated: 2019/06/06 18:18:55 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		changeview(t_build *param);

static void	zoom(int keycode, t_build *param)
{	
	if (keycode == 78)
	{
		mlx_clear_window(param->graph.mlx_ptr, param->graph.mlx_window);
		if (param->map.spc > 0)
			param->map.spc -= 1;
		view(param, 0, 0);
	}
	else
	{
		mlx_clear_window(param->graph.mlx_ptr, param->graph.mlx_window);
		if (param->map.spc <= 80)
			param->map.spc += 1;
		view(param, 0, 0);
	}
}

int			key_press(int keycode, t_build *param)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, param);
	// if (keycode == 34)
	// {
	// 	param->proj = 0 ? 1 : 0;
	// 	changeview(param);
	// }
	return (0);
}
