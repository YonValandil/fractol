#include "fractol.h"

int 		set_color(t_env *env, int i)
{
	return (((i * 255) / (env->fract.i_max)) & BLUE);
}

void         fractol(t_env *env)
{
	int 	i;
	int 	j;
	int 	k;
	int		tmp;
	float	img_x;
	float 	img_y;

	// img_x = (env->fract.x2 - env->fract.x1) * env->fract.zoom;
	img_x = env->fract.x2 - env->fract.x1 * env->fract.zoom;
	// img_y = (env->fract.y2 - env->fract.y1) * env->fract.zoom;
	img_y = env->fract.y2 - env->fract.y1 * env->fract.zoom;
	i = -1;
	while(++i < img_x)
	{
		j = -1;
		while (++j < img_y)
		{
			// env->fract.c_r = i / (env->fract.zoom + env->fract.x1);
			env->fract.c_r = i / env->fract.zoom + env->fract.x1;
			// env->fract.c_i = j / (env->fract.zoom + env->fract.y1);
			env->fract.c_i = j / env->fract.zoom + env->fract.y1;
			k = 0;
			// while ((((env->fract.z_r * env->fract.z_r) + (env->fract.z_i *
			// 	env->fract.z_i)) < 4) && (k < env->fract.i_max))

				tmp = env->fract.z_r;
				// env->fract.z_r = ((env->fract.z_r * env->fract.z_r) -
				// 	(env->fract.z_i * env->fract.z_i)) + env->fract.c_r;
				env->fract.z_r = env->fract.z_r * env->fract.z_r -
					env->fract.z_i * env->fract.z_i + env->fract.c_r;
				env->fract.z_i = 2 * env->fract.z_i * tmp + env->fract.c_i;
				++k;

			while (env->fract.z_r * env->fract.z_r + env->fract.z_i *
				env->fract.z_i < 4 && k < env->fract.i_max)
			{
				tmp = env->fract.z_r;
				// env->fract.z_r = ((env->fract.z_r * env->fract.z_r) -
				// 	(env->fract.z_i * env->fract.z_i)) + env->fract.c_r;
				env->fract.z_r = env->fract.z_r * env->fract.z_r -
					env->fract.z_i * env->fract.z_i + env->fract.c_r;
				env->fract.z_i = 2 * env->fract.z_i * tmp + env->fract.c_i;
				++k;
			}
			if (k == env->fract.i_max)
				put_pixel_img(env, set_pixel(i, j, BLACK));
				// put_pixel_img(env, set_pixel(i, j, RED));
			else
				put_pixel_img(env, set_pixel(i, j, set_color(env, i)));
		}
	}
}
