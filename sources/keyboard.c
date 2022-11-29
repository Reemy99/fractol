/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:28 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:24:18 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_palette(t_event_data *data)
{
	data->fractol_info->palette_index = (data->fractol_info->palette_index + 1)
		% 3;
	draw_fractol(data->appinfo, data->fractol_info);
}

int	key_down_handler(int button, t_event_data *data)
{
	if (button == ON_KEY_ESC)
		exit_app(data);
	else if (button == ON_KEY_PLUS || button == ON_NUMPAD_PLUS
		|| button == ON_KEY_MINUS || button == ON_NUMPAD_MINUS)
		change_max_iteration(button, data);
	else if (button == ON_KEY_C)
		change_palette(data);
	return (0);
}
