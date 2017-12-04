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
	printf("mouse : %d\n", keycode);
	printf("mouse pos : x: %d, y: %d\n", x, y);
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG)
	{
		if (keycode == ZOOM_IN || keycode == 5)
		{
			env->fra.x1 += x - WIDTH_IMG;
			env->fra.y1 += y - HEIGHT_IMG;
			env->fra.zoom *= 1.1;
		}
		if (keycode == ZOOM_OUT || keycode == 4)
		{
			env->fra.x1 -= ;
			env->fra.y1 -= ;
			env->fra.zoom /= 1.1;
		}
		set_img(env);
	}
	return (0);
}

int mouse_pos(int x, int y, t_env *env)
{
	printf("fract == %d\nmouse pos : x: %d, y: %d\n", env->fra.fractal, x, y);
	if (x >= 0 && x <= WIDTH_IMG && y >= 0 && y <= HEIGHT_IMG &&
		env->fra.fractal == 1)
	{
		env->fra.c_r = ;
		env->fra.c_i = ;
		set_img(env);
	}
	return (0);
}

void reset(t_env *env)
{
	env->fra.zoom = 250;
}
