/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:43:53 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:18:17 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_max_iteration(int button, t_event_data *data)
{
	if (button == ON_KEY_PLUS || button == ON_NUMPAD_PLUS)
		data->fractol_info->max_iteration++;
	if (button == ON_KEY_MINUS || button == ON_NUMPAD_MINUS)
		data->fractol_info->max_iteration--;
	if (data->fractol_info->max_iteration < 0)
		data->fractol_info->max_iteration = 0;
	draw_fractol(data->appinfo, data->fractol_info);
}
