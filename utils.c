/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:30 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 22:16:30 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	putstr_fd(char *text, int fd)
{
	if (fd == -1)
		return ;
	while (*text != '\0')
	{
		write (fd, text, 1);
		text++;
	}
}

void	print_list(void)
{
	putstr_fd("julia\n", 1);
	putstr_fd("mandelbrot\n", 1);
}

double	cord_config(int pixel, int axis, double min, double max)
{
	return (min + ((max - min) * pixel) / axis);
}
