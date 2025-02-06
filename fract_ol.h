/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:26:17 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 22:25:25 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
// mlx config
# define TITLE  "Fractol"
# define WIDTH  800
# define HEIGHT 800
//mandelbrot
# define MINX -2.10
# define MAXX 1.00
# define MINY -1.5
# define MAXY 1.5
//julia
# define JMINX -2.00
# define JMAXX 2
# define JMINY 2
# define JMAXY -2

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_hooks
{
	char	*name;
	void	*mlx;
	void	*win;
	double	zoom;
	double	ima;
	double	real;
	t_img	*img;
}				t_hooks;

int		mouse_hook(int keycode, int x, int y, t_hooks *vars);
void	hooks_handler(t_hooks *vars);
void	window(t_hooks vars);
int		main(int ac, char **av);
int		ft_strcmp(const char *str1, const char *str2);
void	putstr_fd(char *text, int fd);
void	print_list(void);
void	put_pixel(t_img *data, int x, int y, int color);
int		key_hook(int keycode, t_hooks *vars);
int		close_win(t_hooks *vars);
void	error_handler(t_hooks *vars);
int		julia(double x, double y, double jx, double jy);
int		mandelbrot(double x, double y);
int		color(int i);
void	draw(t_img *img, t_hooks *vars);
double	cord_config(int pixel, int axis, double min, double max);

#endif