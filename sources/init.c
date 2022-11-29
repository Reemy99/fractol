/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:16 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:31:12 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_imageinfo	*init_imageinfo(void *mlx)
{
	t_imageinfo	*info;

	info = malloc(sizeof(t_imageinfo));
	if (!info)
		debug_log(ERR_IMAGE_INIT);
	info->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!info->image)
		debug_log(ERR_IMAGE_INIT);
	info->addr = mlx_get_data_addr(
			info->image,
			&info->bits_per_pixel,
			&info->line_length,
			&info->endian);
	return (info);
}

void	init_formula(t_fractol_info	*info)
{
	if (str_equal(info->name, "Mandelbrot"))
	{
		info->viewport = init_rect(-2.00, -1.12, 2.47, 2.24);
		info->formula = &get_mandelbrot;
	}
	else if (str_equal(info->name, "Julia set"))
	{
		info->viewport = init_rect(-2, -2, 4, 4);
		info->formula = &get_julia_set;
	}
	else
		info->formula = NULL;
}

void	fractol_reset(t_fractol_info	*info)
{
	static int	max = 0;

	if (max == 0)
		max = info->max_iteration;
	else
		info->max_iteration = max;
	info->zoom = 1.0f;
	info->mouse_pos = init_vector2(0, 0);
	info->palette_index = 0;
}

t_fractol_info	*init_fractolinfo(char *name, int max_iteration,
	t_appinfo *appinfo, t_vector2 complex)
{
	t_fractol_info	*info;

	info = malloc(sizeof(t_fractol_info));
	if (!info)
		debug_log(ERR_FRACTOL_INIT);
	info->name = ft_strdup(name);
	info->imageinfo = init_imageinfo(appinfo->mlx);
	info->max_iteration = max_iteration;
	info->complex = complex;
	init_formula(info);
	fractol_reset(info);
	return (info);
}

t_appinfo	*init_app(char *name)
{
	t_appinfo	*info;

	info = malloc(sizeof(t_appinfo));
	if (!info)
		debug_log(ERR_APP_INIT);
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, WIDTH, HEIGHT, name);
	if (!info->window)
		debug_log(ERR_WINDOW_INIT);
	return (info);
}
