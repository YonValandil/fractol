#include "fractol.h"

void 	init_fractals(t_env *env)
{
	env->fra.zoom = 250;
	env->fra.y1 = -1.2;
	env->fra.y2 = 1.2;
	env->fra.c_r = 0;
	env->fra.c_i = 0;
	if (env->fra.fractal == 0)
	{
		env->fra.x1 = -2.1;
		env->fra.x2 = 0.6;
	}
	if (env->fra.fractal == 1)
	{
		env->fra.x1 = -1;
		env->fra.x2 = 1;
		env->fra.c_r = 0.285;
		env->fra.c_i = 0.01;
	}
	env->fra.deep = 50;
	if (env->fra.fractal == 2)
		env->fra.deep = 50000;
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
	env->fra.img_x = WIDTH_IMG;
	env->fra.img_y = HEIGHT_IMG;
	init_fractals(env);
	env->fra.x = 0;
	env->fra.y = 0;
	env->fra.z_r = 0;
	env->fra.z_i = 0;
}
