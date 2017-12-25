#include "fractol.h"

int			controller(int keycode, void *param)
{
	t_env	*env;

	env = (t_env*)param;

	if (keycode == ESCAPE)
    	exit(EXIT_SUCCESS);
	if (keycode == RESET)
		reset(env);
	set_img(env);
	return (0);
}

void calcul_zoom(t_env *env, int x, int y)
{
	double tmp_x;
	double tmp_y;

	tmp_x = env->tmp_x;
	tmp_y = env->tmp_x;
	tmp_x = (double)x * ((env->fra.x2 - env->fra.x1) / WIDTH) + env->fra.x1;
	tmp_y = (double)y * ((env->fra.y2 - env->fra.y1) / HEIGHT) + env->fra.y1;
	tmp_x -= tmp_x * env->fra.zoom;
	tmp_y -= tmp_y * env->fra.zoom;
	env->fra.x1 = env->fra.x1 * env->fra.zoom + tmp_x;
	env->fra.x2 = env->fra.x2 * env->fra.zoom + tmp_x;
	env->fra.y1 = env->fra.y1 * env->fra.zoom + tmp_y;
	env->fra.y2 = env->fra.y2 * env->fra.zoom + tmp_y;
}

int mouse_zoom(int keycode, int x, int y, t_env *env)
{
	if (env->fra.fractal == 3)
		return (0);
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG)
	{
		env->fra.zoom = 1;
		if (keycode == ZOOM_IN || keycode == 5)
			env->fra.zoom = 1.1;
		if (keycode == ZOOM_OUT || keycode == 4)
			env->fra.zoom /= 1.1;
		if (keycode == ZOOM_OUT || keycode == 4 || keycode == ZOOM_IN || keycode == 5)
		{
			calcul_zoom(env, x, y);
			set_img(env);
		}
	}
	return (0);
}

int mouse_pos(int x, int y, t_env *env)
{
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG &&
		env->fra.fractal == 1)
	{
		env->fra.c_r = (double)(x + 400 - WIDTH_IMG) / 500;
		env->fra.c_i = (double)(y + 400 - HEIGHT_IMG) / 500;
		set_img(env);
	}
	return (0);
}

void reset(t_env *env)
{
	init_fractals(env);
}
