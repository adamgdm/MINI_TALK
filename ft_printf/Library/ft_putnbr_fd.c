/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:38 by agoujdam          #+#    #+#             */
/*   Updated: 2022/11/22 16:04:40 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		count = 11;
	}
	else if (n != -2147483648)
	{
		if (n < 0)
		{
			count += ft_putchar_fd('-', fd);
			count += ft_putnbr_fd(-n, fd);
		}
		else if (n > 9)
		{
			count += ft_putnbr_fd(n / 10, fd);
			count += ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 10)
			count += ft_putchar_fd(n + '0', fd);
	}
	return (count);
}
