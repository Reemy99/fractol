/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:03 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:24:48 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_event_data	init_event_data(t_appinfo *appinfo,
						t_fractol_info *fractol_info)
{
	t_event_data	data;

	data.appinfo = appinfo;
	data.fractol_info = fractol_info;
	return (data);
}

void	register_events(t_appinfo *appinfo, t_event_data *event_data)
{	
	mlx_hook(appinfo->window, 17, 0, exit_app, event_data);
	mlx_hook(appinfo->window, 4, 0, mouse_down_handler, event_data);
	mlx_hook(appinfo->window, 2, 0, key_down_handler, event_data);
}
