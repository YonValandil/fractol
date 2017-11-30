/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:47:30 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/25 23:33:07 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_color(t_env *env, int i)
{
	return ((i * 255 / env->fra.deep));
}

void	fractol(t_env *env)
{
	double			i;
	double			tmp;

	env->fra.x = -1;
	while (++env->fra.x < env->fra.img_x)
	{
		env->fra.y = -1;
		while (++env->fra.y < env->fra.img_y)
		{
			if (env->fra.fractal == 0)
			{
				env->fra.c_r = env->fra.x / (double)env->fra.zoom + env->fra.x1;
				env->fra.c_i = env->fra.y / (double)env->fra.zoom + env->fra.y1;
				env->fra.z_r = 0;
				env->fra.z_i = 0;
			}
			else if (env->fra.fractal == 1)
			{
				env->fra.c_r = 0.285;
				env->fra.c_i = 0.01;
				env->fra.z_r = env->fra.x / (double)env->fra.zoom + env->fra.x1;
				env->fra.z_i = env->fra.y / (double)env->fra.zoom + env->fra.y1;
			}
        	i = -1;
			while (env->fra.z_r * env->fra.z_r + env->fra.z_i * env->fra.z_i < 4
				&& ++i < env->fra.deep)
			{
            	tmp = env->fra.z_r;
            	env->fra.z_r = env->fra.z_r * env->fra.z_r -
					env->fra.z_i * env->fra.z_i + env->fra.c_r;
            	env->fra.z_i = 2 * env->fra.z_i * tmp + env->fra.c_i;
        	}
			// if (i == env->fra.deep)
			// 	put_pixel_img(env, set_pixel(env->fra.x, env->fra.y, BLACK));
			if (i != env->fra.deep)
				put_pixel_img(env, set_pixel(env->fra.x, env->fra.y,
					set_color(env, i)));
    	}
	}
}

void	barnsley(t_env *env)
{
	float rnd;
	int x;
	int y;

	env->fra.deep = 500000;
	while (env->fra.deep--)
	{
		rnd = (float)rand() / RAND_MAX;
		if (rnd <= 0.01)
		{
			env->fra.x2 = 0;
			env->fra.y2 = 0.16 * env->fra.y2;
		}
		else if (rnd <= 0.06)
		{
			env->fra.x2 = -0.15 * env->fra.x2 + 0.28 * env->fra.y2;
			env->fra.y2 = 0.26 * env->fra.x2 + 0.24 * env->fra.y2 + 0.44;
		}
		else if (rnd <= 0.14)
		{
			env->fra.x2 = 0.2 * env->fra.x2 + -0.26 * env->fra.y2;
			env->fra.y2 = 0.23 * env->fra.x2 + 0.22 * env->fra.y2 + 1.6;
		}
		else
		{
			env->fra.x2 = 0.85 * env->fra.x2 + 0.04 * env->fra.y2;
			env->fra.y2 = -0.04 * env->fra.x2 + 0.85 * env->fra.y2 + 1.6;
		}
		x = (env->fra.x2 + 3) * 70;
		y = 800 - env->fra.y2 * 70;
		put_pixel_img(env, set_pixel(x + 200, y - 50, GREEN));
	}
}
