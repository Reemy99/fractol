/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:45:05 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:31:29 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	//retrieved from mlx library
static void	put_pixel(t_imageinfo *info, t_vector2 pixel, int color)
{
	int	pixel_pos;

	pixel_pos = (pixel.y * info->line_length)
		+ (pixel.x * (info->bits_per_pixel / 8));
	*(unsigned int *)&info->addr[pixel_pos] = color;
}

t_vector2	get_pixel_scaled(t_vector2 pixel, t_rect viewport)
{
	t_vector2	pixel_scaled;
	double		ratio;

	ratio = min(WIDTH / viewport.size.x, HEIGHT / viewport.size.y);
	pixel_scaled.x = ((pixel.x - ((WIDTH - viewport.size.x * ratio) / 2))
			+ viewport.pos.x * ratio);
	pixel_scaled.y = ((pixel.y - ((HEIGHT - viewport.size.y * ratio) / 2))
			+ viewport.pos.y * ratio);
	return (pixel_scaled);
}

t_vector2	get_pixel_zoomed(t_vector2 pixel, double zoom, t_rect viewport)
{
	t_vector2	pixel_zoomed;
	double		ratio;

	ratio = min(WIDTH / viewport.size.x, HEIGHT / viewport.size.y);
	pixel_zoomed.x = pixel.x * zoom / ratio;
	pixel_zoomed.y = pixel.y * zoom / ratio;
	return (pixel_zoomed);
}

void	draw_fractol(t_appinfo *appinfo, t_fractol_info *fractolinfo)
{
	t_vector2	pixel;
	int			iteration;
	t_color		color;

	if (!fractolinfo->formula)
		return ;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			iteration = fractolinfo->formula(fractolinfo, pixel);
			color = get_fractol_color(fractolinfo, pixel, iteration);
			put_pixel(fractolinfo->imageinfo, pixel, get_numcolor(color));
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(appinfo->mlx, appinfo->window,
		fractolinfo->imageinfo->image, 0, 0);
}
