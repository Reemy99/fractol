/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:52 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:21:58 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(int x, int y, t_event_data *data)
{
	t_vector2	pos;
	t_rect		viewport;
	double		ratio;
	double		zoom;

	(void)x;
	(void)y;
	viewport = data->fractol_info->viewport;
	ratio = min(WIDTH / viewport.size.x, HEIGHT / viewport.size.y);
	zoom = data->fractol_info->zoom / ZOOM_FACTOR;
	pos = init_vector2(WIDTH / 2, HEIGHT / 2);
	pos = get_pixel_scaled(pos, viewport);
	pos.x = pos.x * zoom / ratio;
	pos.y = pos.y * zoom / ratio;
	data->fractol_info->zoom = zoom;
	draw_fractol(data->appinfo, data->fractol_info);
}

static void	zoom_out(int x, int y, t_event_data *data)
{
	t_vector2	pos;
	t_vector2	prev_pos;
	t_rect		viewport;
	double		ratio;
	double		zoom;

	(void)x;
	(void)y;
	zoom = data->fractol_info->zoom * ZOOM_FACTOR;
	viewport = data->fractol_info->viewport;
	pos = init_vector2(WIDTH / 2, HEIGHT / 2);
	ratio = min(WIDTH / viewport.size.x, HEIGHT / viewport.size.y);
	pos = get_pixel_scaled(pos, viewport);
	prev_pos.x = pos.x * data->fractol_info->zoom / ratio;
	prev_pos.y = pos.y * data->fractol_info->zoom / ratio;
	pos.x = (pos.x * zoom / ratio) - prev_pos.x;
	pos.y = (pos.y * zoom / ratio) - prev_pos.y;
	data->fractol_info->zoom = zoom;
	draw_fractol(data->appinfo, data->fractol_info);
}

int	mouse_down_handler(int button, int x, int y, t_event_data *data)
{
	if (button == ON_MOUSE_SCROLL_UP)
		zoom_out(x, y, data);
	else if (button == ON_MOUSE_SCROLL_DOWN)
		zoom_in(x, y, data);
	return (0);
}
