/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:13:47 by agoujdam          #+#    #+#             */
/*   Updated: 2022/11/22 16:05:25 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putu_fd(unsigned int n, int fd)
{		
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putu_fd(n / 10, fd);
		count += ft_putu_fd(n % 10, fd);
	}
	else if (n < 10)
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
