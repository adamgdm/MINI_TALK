/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:39 by agoujdam          #+#    #+#             */
/*   Updated: 2022/11/22 16:06:10 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex_fd(unsigned long int n, int fd, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_fd(n / 16, fd, c);
		count += ft_puthex_fd(n % 16, fd, c);
		return (count);
	}
	else if (n < 16 && n >= 10
		&& (c >= 65 && c <= 90))
		count += ft_putchar_fd(n + 'A' - 10, fd);
	else if (n < 16 && n >= 10
		&& (c >= 97 && c <= 122))
		count += ft_putchar_fd(n + 'a' - 10, fd);
	else if (n < 10)
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
