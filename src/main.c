#include "fractol.h"

void 		exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

t_coords    set_pixel(int x, int y, int color)
{
    t_coords p;

    p.x = x;
    p.y = y;
    p.color = color;
    return (p);
}

void put_pixel_img(t_env *env, t_coords p)
{
	int		r;
	int		g;
	int		b;

	r = (p.color & 0xFF0000) >> 16;
	g = (p.color & 0xFF00) >> 8;
	b = (p.color & 0xFF);
	if (p.y >= 0 && p.x >= 0 && p.y < HEIGHT_IMG && p.x < WIDTH_IMG)
	{
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 2] = r;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 1] = g;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x)] = b;
	}
}


int         main(int argc, char *argv[])
{
    t_env       env;

    if(argc != 2)
		exit_error("usage: ./fractol mandelbrot|julia|autres");
	if (ft_strstr(argv[1], "mandelbrot") != NULL)
		env.fra.fractal = 0;
	else if (ft_strstr(argv[1], "julia") != NULL)
		env.fra.fractal = 1;
	else if (ft_strstr(argv[1], "barnsley") != NULL)
		env.fra.fractal = 2;
	else
		exit_error("correspond à aucun nom de fractals gérées.");
    set_env(&env);
    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
	set_img(&env);
	mlx_mouse_hook(env.win.ptr, mouse_zoom, &env); //zoom reel
	mlx_hook(env.win.ptr, 2, 3, controller, &env);
	mlx_hook(env.win.ptr, 6, 7, mouse_pos, &env); //pour ensemble de julia
    mlx_loop(env.mlx);
    return (0);
}
