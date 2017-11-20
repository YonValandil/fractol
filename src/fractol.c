#include "fractol.h"

int 		set_color(t_env *env, int i)
{
	return ((i * 255 / env->fract.deep));
}

void 			fractol(t_env *env)
{
	unsigned int	img_x;
	unsigned int	img_y;
	unsigned int	x;
	unsigned int	y;
	double			i;
	double			tmp;

	img_x = (env->fract.x2 - env->fract.x1) * env->fract.zoom;
	img_y = (env->fract.y2 - env->fract.y1) * env->fract.zoom;

	x = -1;
	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
        	env->fract.c_r = x / (double)env->fract.zoom + env->fract.x1;
        	env->fract.c_i = y / (double)env->fract.zoom + env->fract.y1;
        	env->fract.z_r = 0;
        	env->fract.z_i = 0;
        	i = 0;

        	do{
            	tmp = env->fract.z_r;
            	env->fract.z_r = env->fract.z_r*env->fract.z_r - env->fract.z_i*env->fract.z_i + env->fract.c_r;
            	env->fract.z_i = 2*env->fract.z_i*tmp + env->fract.c_i;
            	++i;
        	}while (env->fract.z_r*env->fract.z_r + env->fract.z_i*env->fract.z_i < 4 && i < env->fract.deep);

			if (i == env->fract.deep)
				put_pixel_img(env, set_pixel(x, y, BLUE));
    	}
	}
}
