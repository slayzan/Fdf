/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:30:30 by humarque          #+#    #+#             */
/*   Updated: 2019/06/06 11:02:56 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	changeview(t_build *param);
{
	
}

void	ft_key_hook(int keycode, t_build *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 34)
	{
		param->proj = 0 ? 1 : 0;
		changeview(param);
	}
}

