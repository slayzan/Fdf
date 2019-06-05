/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:09:22 by humarque          #+#    #+#             */
/*   Updated: 2019/05/30 12:55:04 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_build *param)
{
	param->move.x = 0;
	param->move.y = 0;
}

int		main(int argc, char **argv)
{
	t_build		params;

	if (argc == 2)
	{
		params.name = argv[1];
		if (!(parser(&params)))
			return (0);
		else
			init_window(&params);
	}
}
