/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:07:03 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 22:30:53 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(double x, double y, double jx, double jy)
{
	double	tmpx;
	double	new_x;
	double	new_y;
	int		i;

	new_x = x;
	new_y = y;
	i = 0;
	while (i < 100)
	{
		tmpx = (new_x * new_x) - (new_y * new_y) + jx;
		new_y = 2 * new_x * new_y + jy;
		new_x = tmpx;
		if (new_x * new_x + new_y * new_y >= 4)
			break ;
		i++;
	}
	return (i);
}

int	mandelbrot(double x, double y)
{
	double	tmpx;
	double	new_x;
	double	new_y;
	int		i;

	new_x = 0;
	new_y = 0;
	i = 0;
	while (i < 100)
	{
		tmpx = (new_x * new_x) - (new_y * new_y) + x;
		new_y = 2 * new_x * new_y + y;
		new_x = tmpx;
		if (new_x * new_x + new_y * new_y >= 4)
			break ;
		i++;
	}
	return (i);
}

int	color(int i)
{
	int	red;
	int	green;
	int	blue;

	green = (i * 15) % 256;
	red = (i * 5) % 256;
	blue = (i * 25) % 256;
	return ((red << 16) | (green << 8) | blue);
}

int	formula(t_hooks *vars, int y, int x, double *cord)
{
	int	i;

	i = 0;
	if (!(strcmp("julia", vars->name)))
	{
		cord[0] = cord_config(x, WIDTH, JMINX / vars->zoom,
				JMAXX / vars->zoom);
		cord[1] = cord_config(y, HEIGHT, JMINY / vars->zoom,
				JMAXY / vars->zoom);
		i = julia(cord[0], cord[1], vars->real, vars->ima);
		return (i);
	}
	else
	{
		cord[0] = cord_config(x, WIDTH, MINX / vars->zoom,
				MAXX / vars->zoom);
		cord[1] = cord_config(y, HEIGHT, MINY / vars->zoom,
				MAXY / vars->zoom);
		i = mandelbrot(cord[0], cord[1]);
		return (i);
	}
}

void	draw(t_img *img, t_hooks *vars)
{
	int		x;
	int		y;
	double	cord[2];
	int		i;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			i = formula(vars, y, x, cord);
			if (i == 100)
				put_pixel(img, x, y, 0);
			else
				put_pixel(img, x, y, color(i));
			y++;
		}
		x++;
	}
}
