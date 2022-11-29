/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:39 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:31:45 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mandelbrot(t_fractol_info *info, t_vector2 pixel)
{
	int			iteration;
	double		xtemp;
	t_vector2	pixel_scaled;

	pixel_scaled = get_pixel_scaled(pixel, info->viewport);
	pixel_scaled = get_pixel_zoomed(pixel_scaled, info->zoom, info->viewport);
	pixel.x = 0;
	pixel.y = 0;
	iteration = 0;
	while ((pixel.x * pixel.x) + (pixel.y * pixel.y) <= 4
		&& iteration < info->max_iteration)
	{
		xtemp = (pixel.x * pixel.x) - (pixel.y * pixel.y) + pixel_scaled.x;
		pixel.y = (2 * pixel.x * pixel.y) + pixel_scaled.y;
		pixel.x = xtemp;
		iteration++;
	}
	return (iteration);
}
