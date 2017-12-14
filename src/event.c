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

int mouse_zoom(int keycode, int x, int y, t_env *env)
{
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG)
	{
		printf("mouse_zoom => keycode : %d, x: %d, y: %d\n", x, y, keycode);
		if (keycode == ZOOM_IN || keycode == 5)
		{
			env->fra.zoom *= 1.1;
			env->fra.x1 = x - (x - env->fra.x1) / env->fra.zoom;
			env->fra.x2 = x + (env->fra.x2 - x) / env->fra.zoom;
			env->fra.y1 = y + (env->fra.y1 - y) / env->fra.zoom;
			env->fra.y2 = y - (y - env->fra.y2) / env->fra.zoom;

			//env->fra.x1 += (x - WIDTH_IMG / 2) / (double)WIDTH_IMG / env->fra.zoom;
			//env->fra.y1 += (y - HEIGHT_IMG / 2) / (double)HEIGHT_IMG / env->fra.zoom;
		}
		if (keycode == ZOOM_OUT || keycode == 4)
		{
			env->fra.zoom /= 1.1;
			env->fra.x1 = x - (x - env->fra.x1) / (double)env->fra.zoom;
			env->fra.x2 = x + (env->fra.x2 - x) / (double)env->fra.zoom;
			env->fra.y1 = y + (env->fra.y1 - y) / (double)env->fra.zoom;
			env->fra.y2 = y - (y - env->fra.y2) / (double)env->fra.zoom;

			//env->fra.x1 -= (x - WIDTH_IMG / 2) / (double)WIDTH_IMG / env->fra.zoom;
			//env->fra.y1 -= (y - HEIGHT_IMG / 2) / (double)HEIGHT_IMG / env->fra.zoom;
		}
		set_img(env);
	}
	return (0);
}

int mouse_pos(int x, int y, t_env *env)
{
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG &&
		env->fra.fractal == 1)
	{
		printf("mouse_pos => x: %d, y: %d\n", x, y);
		//env->fra.c_r = x;
		//env->fra.c_i = y;

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
