/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:47:23 by jjourne           #+#    #+#             */
/*   Updated: 2017/11/25 10:49:33 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		controller(int keycode, void *param)
{
	t_env	*env;

	env = (t_env*)param;

	if (keycode == ESCAPE)
    	exit(EXIT_SUCCESS);
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		scale(keycode, env);
	if (keycode == RESET)
		reset(env);
	set_img(env);
	return (0);
}

void	scale(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN)
	{
		env->fra.zoom += 2;
	}
	if (keycode == ZOOM_OUT)
	{
		env->fra.zoom -= 2;
	}
}

void	reset(t_env *env)
{
	env->fra.zoom = 900;
}
