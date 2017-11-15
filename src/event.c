#include "FdF.h"

int			controller(int keycode, void *param)
{
	t_env	*env;

	env = (t_env*)param;

	if (keycode == ESCAPE)
	{
		ft_lstdel(&(env)->map, del_map);
    	exit(EXIT_SUCCESS);
	}
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		scale(keycode, env);
	if (keycode == RESET)
		reset(env);
	set_img(env);
	return (0);
}

void scale(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN)
	{
		env->scalex += 2;
		env->scaley += 1;
	}
	if (keycode == ZOOM_OUT)
	{
		env->scalex -= 2;
		env->scaley -= 1;
	}
}

void reset(t_env *env)
{
	env->height = 5;
	env->scalex = 30;
	env->scaley = 15;
	env->posx = (WIDTH_IMG / 2) + 125;
	env->posy = 100;
}
