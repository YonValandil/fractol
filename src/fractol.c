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
	double	i;
	double	tmp;

	if (env->fra.fractal == 3)
	{
		barnsley(env);
		return ;
	}
	i = -1;
	tmp = -1;
	env->fra.y = -1;
	while (++env->fra.y < HEIGHT)
	{
		env->fra.x = -1;
		while (++env->fra.x < WIDTH)
		{
			if (env->fra.fractal == 0)
				mandelbrot(env, i, tmp);
			if (env->fra.fractal == 1)
				julia(env, i, tmp);
			if (env->fra.fractal == 2)
				tricorn(env, i, tmp);
		}
	}
}

void	julia(t_env *env, double i, double tmp)
{
	env->fra.z_r = env->fra.x1 + env->fra.x *
		((env->fra.x2 - env->fra.x1) / WIDTH);
	env->fra.z_i = env->fra.y1 + env->fra.y *
		((env->fra.y2 - env->fra.y1) / HEIGHT);
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

void	mandelbrot(t_env *env, double i, double tmp)
{
	env->fra.c_r = env->fra.x1 + env->fra.x *
		((env->fra.x2 - env->fra.x1) / WIDTH);
	env->fra.c_i = env->fra.y1 + env->fra.y *
		((env->fra.y2 - env->fra.y1) / HEIGHT);
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

void	tricorn(t_env *env, double i, double tmp)
{
	env->fra.c_r = env->fra.x1 + env->fra.x *
		((env->fra.x2 - env->fra.x1) / WIDTH);
	env->fra.c_i = env->fra.y1 + env->fra.y *
		((env->fra.y2 - env->fra.y1) / HEIGHT);
	env->fra.z_r = 0;
	env->fra.z_i = 0;
	i = -1;
	while (env->fra.z_r * env->fra.z_r + env->fra.z_i * env->fra.z_i < 4
		&& ++i < env->fra.deep)
	{
		tmp = env->fra.z_r;
		env->fra.z_r = env->fra.z_r * env->fra.z_r -
			env->fra.z_i * env->fra.z_i + env->fra.c_r;
		env->fra.z_i = -2 * env->fra.z_i * tmp + env->fra.c_i;
	}
	if (i != env->fra.deep)
		put_pixel_img(env, set_pixel(env->fra.x, env->fra.y,
			i * 255 / env->fra.deep));
}
