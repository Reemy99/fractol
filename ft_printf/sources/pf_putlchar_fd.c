/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:29:30 by fkhan             #+#    #+#             */
/*   Updated: 2022/11/17 17:56:44 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putlchar_fd(char c, int fd, struct s_data data)
{
	int	len;

	len = 1;
	if (!data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	ft_putchar_fd(c, fd);
	if (data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}
