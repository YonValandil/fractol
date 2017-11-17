#include "fractol.h"

int 		set_color(t_env *env, int i)
{
	return ((i * 255 / env->fract.deep));
}

// void         fractol(t_env *env)
// {
// 	int 	i;
// 	int 	j;
// 	int 	k;
// 	int		tmp;
// 	float	img_x;
// 	float 	img_y;
//
// 	img_x = (env->fract.x2 - env->fract.x1) * env->fract.zoom;
// 	img_y = (env->fract.y2 - env->fract.y1) * env->fract.zoom;
// 	i = -1;
// 	while(++i < img_x)
// 	{
// 		j = -1;
// 		while (++j < img_y)
// 		{
// 			env->fract.c_r = i / env->fract.zoom + env->fract.x1;
// 			env->fract.c_i = j / env->fract.zoom + env->fract.y1;
// 			env->fract.z_r = 0;
// 			env->fract.z_i = 0;
// 			k = 0;
// 			while (env->fract.z_r * env->fract.z_r + env->fract.z_i *
// 				env->fract.z_i < 4 && k < env->fract.deep)
// 			{
// 				tmp = env->fract.z_r;
// 				env->fract.z_r = env->fract.z_r * env->fract.z_r -
// 					env->fract.z_i * env->fract.z_i + env->fract.c_r;
// 				env->fract.z_i = 2 * env->fract.z_i * tmp + env->fract.c_i;
// 				++k;
// 			}
// 			if (k == env->fract.deep)
// 				put_pixel_img(env, set_pixel(i, j, RED));
// 		}
// 	}
// }

void 		fractol(t_env *env)
{
	int x;
	int y;
	int i;
	int j;
	int n;

	i = -1;
	x = env->fract.x1;
	while (++i <= 450)
	{
		x = env->fract.x1 + (env->fract.x2 - env->fract.x1) * i /450;
		j = -1;
		while (++j <= 450)
		{
			y = env->fract.y1 + (env->fract.y2 - env->fract.y1) - j / 450;
			env->fract.z_r = 0;
			env->fract.z_i = 0;
			n = -1;
			while (++n < env->fract.deep && env->fract.z_r * env->fract.z_r +
				env->fract.z_i * env->fract.z_i < 4 )
			{
				env->fract.c_r = env->fract.z_r;
				env->fract.c_i = env->fract.z_i;
				env->fract.z_r = env->fract.c_r * env->fract.c_r -
					env->fract.c_i * env->fract.c_i + x;
				env->fract.z_i = 2 * env->fract.c_r * env->fract.c_i + y;
			}
			if (n == env->fract.deep)
				put_pixel_img(env, set_pixel(i , j, RED));
			else
				put_pixel_img(env, set_pixel(i , j, BLUE));
		}
	}
}
