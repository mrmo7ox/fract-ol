/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:41:12 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 22:52:50 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int keycode, int x, int y, t_hooks *vars)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		vars->zoom *= 1.1;
	else if (keycode == 5)
		vars->zoom /= 1.1;
	draw(vars->img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

void	hooks_handler(t_hooks *vars)
{
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, key_hook, vars);
}

void	window(t_hooks vars)
{
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return ;
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, TITLE);
	if (!vars.win)
		(mlx_destroy_display(vars.mlx), free(vars.mlx), exit(0));
	vars.zoom = 1;
	vars.img = malloc(sizeof(t_img));
	if (!vars.img)
		(error_handler(&vars), exit(0));
	vars.img->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (!vars.img->img)
		(error_handler(&vars), free(vars.img), exit(0));
	vars.img->addr = mlx_get_data_addr(vars.img->img, &vars.img->bits_per_pixel,
			&vars.img->line_length, &vars.img->endian);
	draw(vars.img, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	hooks_handler(&vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	t_hooks	vars;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")))
	{
		vars.name = av[1];
		window(vars);
	}
	else if ((ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		vars.name = av[1];
		vars.real = strtod(av[2], NULL);
		vars.ima = strtod(av[3], NULL);
		window(vars);
	}
	else
		print_list();
	return (0);
}
