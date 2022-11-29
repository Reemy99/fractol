/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:23 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:31:57 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia_set(t_fractol_info *info, t_vector2 pixel)
{
	int			iteration;
	double		xtemp;
	t_vector2	pixel_scaled;

	pixel_scaled = get_pixel_scaled(pixel, info->viewport);
	pixel_scaled = get_pixel_zoomed(pixel_scaled, info->zoom, info->viewport);
	pixel.x = pixel_scaled.x;
	pixel.y = pixel_scaled.y;
	iteration = 0;
	while ((pixel.x * pixel.x) + (pixel.y * pixel.y) <= 4
		&& iteration < info->max_iteration)
	{
		xtemp = (pixel.x * pixel.x) - (pixel.y * pixel.y) + info->complex.x;
		pixel.y = (2 * pixel.x * pixel.y) + info->complex.y;
		pixel.x = xtemp;
		iteration++;
	}
	return (iteration);
}
