/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:57:16 by humarque          #+#    #+#             */
/*   Updated: 2019/05/21 14:31:30 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_countwords(char *line)
{
	int		resultat;
	int		i;
	int		number;
	char	space;

	number = 0;
	i = 0;
	space = ' ';
	resultat = 0;
	while (line[i])
	{
		if (number == 1 && line[i] == space)
			number = 0;
		if (number == 0 && line[i] != space)
		{
			resultat++;
			number = 1;
		}
		i++;
	}
	return (resultat);
}

static void		ft_freesave(char **save)
{
	int i;

	i = 0;
	while (save[i])
		ft_memdel((void **)&save[i++]);
	ft_memdel((void **)&save);
}

static int		check_str(t_build *param, int fd)
{
	char	*line;
	char	**save;
	int		words;
	int		i;
	int		flag;
	int		p;

	line = NULL;
	flag = 0;
	p = 0;
	param->map.hauteur = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag == 0)
		{
			if (!(words = ft_countwords(line)))
			{
				ft_putendl("error file");
				return (0);
			}
			flag = 1;
			param->map.taille = words;
		}
		save = ft_strsplit(line, ' ');
		i = 0;
		while (save[i])
		{
			param->map.grille[p] = ft_atoi(save[i]);
			i++;
			p++;
		}
		param->map.hauteur++;
		ft_freesave(save);
		free(line);
	}
	return (1);
}

int				parser(t_build *param)
{
	int		fd;

	fd = open(param->name, O_RDONLY);
	if (!(check_str(param, fd)))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
