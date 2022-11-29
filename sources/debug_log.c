/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:43:13 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/27 16:46:19 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	debug_log(char *log)
{
	ft_printf("%s\n", log);
	exit(0);
}

void	print_help(void)
{
	ft_printf("Usage: ./fractol <fractal name>\n");
	ft_printf("You can choose 1 one of the fractals below\n");
	ft_printf("List of available fractals:\n");
	ft_printf("* Mandelbrot\n");
	ft_printf("* Julia set (with optional two float parameters)\n");
}
