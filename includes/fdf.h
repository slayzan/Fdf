/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:58:25 by humarque          #+#    #+#             */
/*   Updated: 2019/05/29 18:25:26 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# define BUFFER 1280 * 720
# define SPC_PIXEL 30
# define HEIGHT 720
# define WIDTH 1280

typedef	struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct s_move
{
	int		z;
	int		blanck;
	int		x;
	int		y;
}			t_move;
typedef struct	s_map
{
	int taille;
	int hauteur;
	int midx;
	int midy;
	int sx;
	int sy;
	int grille[BUFFER];
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	img;
}				t_mlx;

typedef struct	s_build
{
	char	*name;
	int		first;
	int		proj;
	t_map	map;
	t_move move;
}				t_build;

int				ft_parser(t_build *param);
void			init_window(t_build *param);
void			view(t_mlx *graph,t_build *param, int x, int y, int z);
void			bresenham(int x1, int y1, int x2, int y2, t_mlx *graph);
void			draw(t_mlx *graph,t_build *param);		
#endif
