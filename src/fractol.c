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

void	fractals(t_env *env)
{
	double			i;
	double			tmp;

	if (env->fra.fractal == 2)
	{
		barnsley(env);
		return ;
	}
	i = -1;
	tmp = -1;
	env->fra.x = -1;
	while (++env->fra.x < env->fra.img_x)
	{
		env->fra.y = -1;
		while (++env->fra.y < env->fra.img_y)
		{
			if (env->fra.fractal == 0)
				mandelbrot(env, i, tmp);
			if (env->fra.fractal == 1)
				julia(env, i, tmp);
    	}
	}
}

void 	julia(t_env *env, double i, double tmp)
{
	env->fra.x1 = -1;
	env->fra.x2 = 1;
	env->fra.c_r = 0.285;
	env->fra.c_i = 0.01;
	env->fra.z_r = env->fra.x / (double)env->fra.zoom + env->fra.x1;
	env->fra.z_i = env->fra.y / (double)env->fra.zoom + env->fra.y1;
	i = -1;
	while (env->fra.z_r * env->fra.z_r + env->fra.z_i * env->fra.z_i < 4
		&& ++i < env->fra.deep)
	{
    	tmp = env->fra.z_r;
    	env->fra.z_r = env->fra.z_r * env->fra.z_r -
			env->fra.z_i * env->fra.z_i + env->fra.c_r;
    	env->fra.z_i = 2 * env->fra.z_i * tmp + env->fra.c_i;
	}
	if (i != env->fra.deep)
		put_pixel_img(env, set_pixel(env->fra.x + 200, env->fra.y,
			i * 255 / env->fra.deep));
}

void 	mandelbrot(t_env *env, double i, double tmp)
{
	env->fra.x1 = -2.1;
	env->fra.x2 = 0.6;
	env->fra.c_r = env->fra.x / (double)env->fra.zoom + env->fra.x1;
	env->fra.c_i = env->fra.y / (double)env->fra.zoom + env->fra.y1;
	env->fra.z_r = 0;
	env->fra.z_i = 0;
	i = -1;
	while (env->fra.z_r * env->fra.z_r + env->fra.z_i * env->fra.z_i < 4
		&& ++i < env->fra.deep)
	{
    	tmp = env->fra.z_r;
    	env->fra.z_r = env->fra.z_r * env->fra.z_r -
			env->fra.z_i * env->fra.z_i + env->fra.c_r;
    	env->fra.z_i = 2 * env->fra.z_i * tmp + env->fra.c_i;
	}
	if (i != env->fra.deep)
		put_pixel_img(env, set_pixel(env->fra.x, env->fra.y,
			i * 255 / env->fra.deep));
}

void	barnsley(t_env *env)
{
	float rnd;
	t_coords c;

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
		c.x = (env->fra.x2 + 3) * 70;
		c.y = 800 - env->fra.y2 * 70;
		put_pixel_img(env, set_pixel(c.x + 200, c.y - 100, GREEN));
	}
}
