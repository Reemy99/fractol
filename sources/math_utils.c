/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:44:45 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/23 11:44:47 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vector2	init_vector2(double x, double y)
{
	t_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

t_rect	init_rect(double x, double y, double w, double h)
{
	t_rect	rect;

	rect.pos = init_vector2(x, y);
	rect.size = init_vector2(w, h);
	return (rect);
}

double	min(double num1, double num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}
