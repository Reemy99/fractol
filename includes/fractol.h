/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:50:25 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:29:13 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include "debug_log.h"
# include "structs.h"
# include <mlx.h>
# include <math.h>
# include <stdint.h>

# define WIDTH			1000
# define HEIGHT			1000
# define ZOOM_FACTOR 	2

enum {
	ON_MOUSE_SCROLL_UP = 4,
	ON_MOUSE_SCROLL_DOWN = 5,
	ON_KEY_PLUS = 24,
	ON_KEY_MINUS = 27,
	ON_NUMPAD_PLUS = 69,
	ON_NUMPAD_MINUS = 78,
	ON_KEY_ESC = 53,
	ON_KEY_C = 8,
};

// fractol
int				exit_app(t_event_data *event_data);

// init
t_appinfo		*init_app(char *name);
t_fractol_info	*init_fractolinfo(char *name, int max_iteration,
					t_appinfo *appinfo, t_vector2 complex);
t_imageinfo		*init_imageinfo(void *mlx);
void			fractol_reset(t_fractol_info	*info);
void			init_formula(t_fractol_info	*info);

// events
t_event_data	init_event_data(t_appinfo *appinfo, t_fractol_info *fractolinfo);
void			register_events(t_appinfo *appinfo, t_event_data *event_data);

// render
void			draw_fractol(t_appinfo *appinfo, t_fractol_info *fractolinfo);
t_vector2		get_pixel_scaled(t_vector2 pixel, t_rect viewport);
t_vector2		get_pixel_zoomed(t_vector2 pixel, double zoom, t_rect viewport);

// math_utils
t_vector2		init_vector2(double x, double y);
t_rect			init_rect(double x, double y, double w, double h);
double			min(double num1, double num2);

// str_utils
int				str_equal(char *str1, char *str2);

// mandelbrot
int				get_mandelbrot(t_fractol_info *info, t_vector2 pixel);

// julia_set
int				get_julia_set(t_fractol_info *info, t_vector2 pixel);

// colors
t_color			create_trgb(int t, int r, int g, int b);
int				get_numcolor(t_color color);
t_color			get_fractol_color( t_fractol_info *info, t_vector2 pixel,
					int iteration);

// mouse
int				mouse_down_handler(int button, int x, int y,
					t_event_data *data);

// keyboard
int				key_down_handler(int button, t_event_data	*data);

// controls
void			change_max_iteration(int button, t_event_data *data);

// palette
t_palette		get_palette(int index);

// utils
double			ft_atof(char *s);

#endif