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
