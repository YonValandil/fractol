/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:32:06 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/25 20:33:03 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	barnsley_step_one(t_env *env)
{
	env->fra.x2 = 0;
	env->fra.y2 = 0.16 * env->fra.y2;
}

void	barnsley_step_two(t_env *env)
{
	env->fra.x2 = -0.15 * env->fra.x2 + 0.28 * env->fra.y2;
	env->fra.y2 = 0.26 * env->fra.x2 + 0.24 * env->fra.y2 + 0.44;
}

void	barnsley(t_env *env)
{
	float		rnd;
	t_coords	c;

	while (env->fra.deep--)
	{
		rnd = (float)rand() / RAND_MAX;
		if (rnd <= 0.01)
			barnsley_step_one(env);
		else if (rnd <= 0.06)
			barnsley_step_two(env);
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
