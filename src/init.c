#include "fractol.h"

t_coords    set_pixel(int x, int y, int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;

    return (p);
}

void put_pixel_img(t_env *env, t_coords p)
{
	int		r;
	int		g;
	int		b;

	r = (p.color & 0xFF0000) >> 16;
	g = (p.color & 0xFF00) >> 8;
	b = (p.color & 0xFF);
	if (p.y >= 0 && p.x >= 0 && p.y < HEIGHT_IMG && p.x < WIDTH_IMG)
	{
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 2] = r;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 1] = g;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x)] = b;
	}
}

void set_string(t_env *env)
{
	mlx_string_put(env->mlx, env->win.ptr, 20, 20, GREEN,
		"press ESC: QUIT");
	mlx_string_put(env->mlx, env->win.ptr, 20, 40, GREEN,
		"press SPACE: RESET");
	mlx_string_put(env->mlx, env->win.ptr, 220, 20, GREEN,
		"press T: ZOOM UP");
	mlx_string_put(env->mlx, env->win.ptr, 220, 40, GREEN,
		"press G: ZOOM DOWN");
}

void set_img(t_env *env)
{
    env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
    env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
    	&env->img.size_line, &env->img.endian);
	mlx_clear_window(env->mlx, env->win.ptr);
	fractals(env);
    mlx_put_image_to_window(env->mlx, env->win.ptr, env->img.ptr, 0, 0);
	set_string(env);
	mlx_destroy_image(env->mlx, env->img.ptr);
}

void set_env(t_env *env)
{
    env->win.l = WIDTH;
    env->win.h = HEIGHT;
    env->win.title = ft_strdup("mlx 42 Fract-ol");
    env->img.l = WIDTH_IMG;
    env->img.h = HEIGHT_IMG;
	init_fractals(env);
	env->fra.zoom = 250;
	env->fra.img_x = WIDTH_IMG;
	env->fra.img_y = HEIGHT_IMG;
	env->fra.x = 0;
	env->fra.y = 0;
	env->fra.c_r = 0;
	env->fra.c_i = 0;
	env->fra.z_r = 0;
	env->fra.z_i = 0;
}
