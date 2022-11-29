/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:45:20 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/29 12:39:12 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *s)
{
	int		i;
	int		neg;
	double	d;
	double	temp;

	i = 0;
	d = 0;
	neg = 1;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && s[i] != '.')
		d = d * 10 + (s[i++] - '0');
	if (s[i] && s[i] == '.')
		i++;
	temp = 0.1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		d += (s[i++] - '0') * temp;
		temp /= 10;
	}
	return (neg * d);
}
