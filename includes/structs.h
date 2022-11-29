/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:27:03 by realdahh          #+#    #+#             */
/*   Updated: 2022/11/29 12:23:40 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"

typedef struct s_vector2
{
	double	x;
	double	y;
}				t_vector2;

typedef struct s_color
{
	int8_t	channel[4];
}	t_color;

typedef struct s_palette
{
	t_color	*colors;
	int		size;
}				t_palette;

typedef struct s_rect
{
	t_vector2		pos;
	t_vector2		size;
}				t_rect;

typedef struct s_imageinfo
{
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_imageinfo;

typedef struct s_fractol_info
{
	char			*name;
	t_imageinfo		*imageinfo;
	int				max_iteration;
	int				(*formula)(struct s_fractol_info *, t_vector2);
	t_rect			viewport;
	int				palette_index;
	double			zoom;
	t_vector2		complex;
	t_vector2		mouse_pos;
}				t_fractol_info;

typedef struct s_appinfo
{
	void	*mlx;
	void	*window;
}				t_appinfo;

typedef struct s_event_data
{
	t_appinfo		*appinfo;
	t_fractol_info	*fractol_info;
}				t_event_data;
#endif