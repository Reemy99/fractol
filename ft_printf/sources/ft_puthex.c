/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:03:20 by fkhan             #+#    #+#             */
/*   Updated: 2022/11/17 17:56:40 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long num, int fd, int isupper)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, fd, isupper);
		ft_puthex(num % 16, fd, isupper);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (isupper)
				ft_putchar_fd((num - 10 + 'A'), fd);
			else
				ft_putchar_fd((num - 10 + 'a'), fd);
		}
	}
}
