/* ************************************************************************** */
/*                                                                         */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:06:51 by galambey          #+#    #+#             */
/*   Updated: 2024/04/13 11:28:04 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "librairies.h"

/* ********************************* MACRO ********************************* */

# define ALLOWD_CHAR "01EWNS R"
# define ALLOWD_BRD "01EWNS"
# define TRUE 1
# define FALSE 0
# define WIDTH 800
# define HEIGHT 600
# define PI 3.141592653589793238462643383279502884197

/* ******************************* STRUCTURE ******************************* */

typedef struct s_color
{
	int			empty;
	int			r;
	int			g;
	int			b;
	int			color;
}				t_color;

typedef struct s_draw
{
	double		hp;
	double		hr;
	double		tx;
	double		ty;
	double		ty_inc;
	double		ty_off;
	int			start;
	int			end;
}				t_draw;

typedef struct s_ray
{
	double		a;
	double		tan_a;
	double		xes;
	double		yes;
	double		xeh;
	double		yeh;
	double		xev;
	double		yev;
	double		dist_wh;
	double		dist_wv;
	double		dist_w;
	int			hit;
	int			xe;
	int			ye;
}				t_ray;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	int			size;
}				t_img;

typedef struct s_texture
{
	char		**tex;
	t_img		n_wall;
	t_img		s_wall;
	t_img		w_wall;
	t_img		e_wall;
	t_color		color[2];
}				t_texture;

typedef struct s_map
{
	char		**map_final;
	int			map_height;
	int			map_width;
	t_list		*mapfinal;
	int			fd;
	t_texture	t;
}				t_map;

typedef struct s_player
{
	double		x_pos;
	double		y_pos;
	double		cos_mv;
	double		sin_mv;
	double		pa;
}				t_player;

typedef struct s_key
{
	bool		a;
	bool		w;
	bool		d;
	bool		s;
	bool		r;
	bool		l;
}				t_key;

typedef struct s_parsing
{
	int			len_x;
	int			len_y;
}				t_parsing;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	double		speed;
	int			inc_a;
	t_img		img;
	t_map		map;
	t_player	p;
	t_ray		ray;
	t_draw		draw;
	t_key		key;
	t_parsing	parsing;
}				t_cub;

typedef struct s_pt
{
	int			x;
	int			yo;
	int			ye;
}				t_pt;

/* ********************************** ENUM ********************************* */

enum			e_malloc
{
	MLC,
	ADD,
	FREE,
	FLUSH,
	QUIT,
	PRINT,
};

enum			e_texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
};

#endif