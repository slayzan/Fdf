/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:09:22 by humarque          #+#    #+#             */
/*   Updated: 2019/06/06 11:01:56 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_build		*param;

	if (argc == 2)
	{
		param->name = argv[1];
		if (parser(param) == 0)
		{
			ft_putstr("error file\n");
			return (0);
		}
		else
			init_window(param);
	}
	return (0);
}
