/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:57:16 by humarque          #+#    #+#             */
/*   Updated: 2019/06/14 16:14:54 by kwatanab         ###   ########.fr       */
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

static t_build	*grille(t_build *param, char **save, int *i, int *p)
{
	while (save[*i])
	{
		param->map.grille[*p] = ft_atoi(save[*i]);
		*i += 1;
		*p += 1;
	}
	param->map.hauteur++;
	return (param);
}

static int		check_str(t_build *param, int fd, char *line)
{
	char	**save;
	int		words;
	int		i;
	int		flag;
	int		p;

	flag = 0;
	p = 0;
	param->map.hauteur = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag == 0)
		{
			if (!(words = ft_countwords(line)))
				return (0);
			flag = 1;
			param->map.taille = words;
		}
		save = ft_strsplit(line, ' ');
		i = 0;
		param = grille(param, save, &i, &p);
		ft_freesave(save);
		free(line);
	}
	return (1);
}

int				parser(t_build *param)
{
	int		fd;
	char	*line;

	fd = open(param->name, O_RDONLY);
	line = NULL;
	if (fd == -1)
		return (0);
	if (check_str(param, fd, line) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
