/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:10:30 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 23:10:31 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0)
	{
		if (n >= -9 && n <= 9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + (n % 10), fd);
}
