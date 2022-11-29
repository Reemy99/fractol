/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:45:12 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/23 11:45:14 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	str_equal(char *str1, char *str2)
{
	if (ft_strlen(str1) == ft_strlen(str2)
		&& !ft_strncmp(str1, str2, ft_strlen(str1)))
		return (1);
	return (0);
}
