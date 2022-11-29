/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:43:38 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:32:59 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	create_trgb(int t, int r, int g, int b)
{
	t_color	color;

	color.channel[0] = t;
	color.channel[1] = r;
	color.channel[2] = g;
	color.channel[3] = b;
	return (color);
}

int	get_numcolor(t_color color)
{
	return (color.channel[0] << 24 | color.channel[1] << 16
		| color.channel[2] << 8 | color.channel[3]);
}

t_color	lerp_color(t_color a, t_color b, double t)
{
	return (create_trgb(
			a.channel[0] + (b.channel[0] - a.channel[0]) * t,
			a.channel[1] + (b.channel[1] - a.channel[1]) * t,
			a.channel[2] + (b.channel[2] - a.channel[2]) * t,
			a.channel[3] + (b.channel[3] - a.channel[3]) * t
		));
}

t_color	linear_color(double i, int max, t_palette palette)
{
	double	index;
	int		size;
	double	t;

	index = i / max;
	size = palette.size - 1;
	t = fmod(index, 1.0f / size) * size;
	return (lerp_color(palette.colors[(int)(index * size)],
		palette.colors[(int)(index * size) + 1],
		t)
	);
}

t_color	get_fractol_color(t_fractol_info *info, t_vector2 pixel, int iteration)
{
	t_palette	palette;
	t_color		color;

	(void)pixel;
	if (iteration == info->max_iteration)
		return (create_trgb(0, 0, 0, 0));
	palette = get_palette(info->palette_index);
	if (!palette.colors)
		return (create_trgb(0, 255, 255, 255));
	color = linear_color((double)iteration, info->max_iteration, palette);
	free(palette.colors);
	return (color);
}
