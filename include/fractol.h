/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:22:19 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/25 19:22:20 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

# define BLANK			0x00FFFFFF
# define BLACK			0x00000000
# define BLUE			0x000000FF
# define GREEN			0x0000FF00
# define RED			0x00FF0000
# define RANGE_MAP		100000000
# define RANGE_HEIGHT	100000000
# define HEIGHT			600
# define WIDTH			600
# define HEIGHT_IMG		600
# define WIDTH_IMG		600

# if defined(linux) || defined(__linux) || defined(__linux__)
#  define ZOOM_IN		1
#  define ZOOM_OUT		3
#  define ESCAPE		65307
#  define RESET			32
# elif defined(__APPLE__)
#  define ZOOM_IN		1
#  define ZOOM_OUT		2
#  define ESCAPE		53
#  define RESET			49
# endif

typedef struct			s_coords
{
	int					x;
	int					y;
	unsigned int		color;
}						t_coords;

typedef struct			s_fractal
{
	int					fractal;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				zoom;
	unsigned int		zoom_x;
	unsigned int		zoom_y;
	unsigned int		deep;
	unsigned int		img_x;
	unsigned int		img_y;
	unsigned int		x;
	unsigned int		y;
}						t_fractal;

typedef struct			s_img
{
	int					l;
	int					h;
	int					bpp;
	int					size_line;
	int					endian;
	void				*ptr;
	char				*data;
}						t_img;

typedef struct			s_win
{
	int					l;
	int					h;
	void				*ptr;
	char				*title;
}						t_win;

typedef struct			s_env
{
	void				*mlx;
	int					tmp_x;
	int					tmp_y;
	struct s_img		img;
	struct s_win		win;
	struct s_fractal	fra;
}						t_env;

void					exit_error(const char *s);
void					set_env(t_env *env);
void					set_img(t_env *env);
void					set_string(t_env *env);
void					init_fractals(t_env *env);
void					fractals(t_env *env);
void					julia(t_env *env, double i, double tmp);
void					tricorn(t_env *env, double i, double tmp);
void					mandelbrot(t_env *env, double i, double tmp);
void					barnsley(t_env *env);
void					put_pixel_img(t_env *env, t_coords p);
t_coords				set_pixel(int x, int y, int color);
int						controller(int keycode, void *param);
int						mouse_pos(int x, int y, t_env *env);
void					calcul_zoom(t_env *env, int x, int y);
int						mouse_zoom(int keycode, int x, int y, t_env *env);
void					reset(t_env *env);

#endif
