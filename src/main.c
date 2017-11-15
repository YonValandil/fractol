#include "fractol.h"

void 		exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int         main(int argc, char *argv[])
{
    t_env       env;

    if(argc != 2)
		exit_error("usage: ./fractol mandelbrot|julia|autres");
    set_env(&env);
    env.mlx = mlx_init();
    env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
	set_img(&env);
	mlx_hook(env.win.ptr, 2, 3, controller, &env);
    mlx_loop(env.mlx);
    return (0);
}
