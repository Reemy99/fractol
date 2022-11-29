/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:57 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/28 17:05:44 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	first_pal(t_palette *palette)
{
	palette->colors[0] = create_trgb(0, 111, 98, 62);
	palette->colors[1] = create_trgb(0, 55, 14, 62);
	palette->colors[2] = create_trgb(0, 82, 11, 41);
	palette->colors[3] = create_trgb(0, 55, 14, 62);
	palette->colors[4] = create_trgb(0, 111, 98, 62);
}

static void	sec_pal(t_palette *palette)
{
	palette->colors[0] = create_trgb(0, 82, 11, 41);
	palette->colors[1] = create_trgb(0, 111, 98, 62);
	palette->colors[2] = create_trgb(0, 111, 98, 62);
	palette->colors[3] = create_trgb(0, 55, 14, 62);
	palette->colors[4] = create_trgb(0, 55, 14, 62);
}

static void	third_pal(t_palette *palette)
{
	palette->colors[0] = create_trgb(0, 55, 14, 62);
	palette->colors[1] = create_trgb(0, 111, 98, 62);
	palette->colors[2] = create_trgb(0, 111, 98, 62);
	palette->colors[3] = create_trgb(0, 55, 14, 62);
	palette->colors[4] = create_trgb(0, 55, 14, 62);
}

t_palette	get_palette(int index)
{
	t_palette	palette;

	palette.size = 5;
	palette.colors = malloc(sizeof(t_palette) * palette.size);
	if (!palette.colors)
		return (palette);
	if (index == 0)
		first_pal(&palette);
	else if (index == 1)
		sec_pal(&palette);
	else if (index == 2)
		third_pal(&palette);
	return (palette);
}
