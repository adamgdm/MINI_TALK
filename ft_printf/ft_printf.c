/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:32:33 by agoujdam          #+#    #+#             */
/*   Updated: 2023/01/19 22:16:15 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_do_it(const char c, void *p, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd((char)p, fd));
	else if (c == 's') 
	{
		if (p == NULL)
			return (ft_putstr_fd("(null)", fd));
		return (ft_putstr_fd((char *)p, fd));
	}
	else if (c == 'p')
		return (ft_printp_fd(p, fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)p, fd));
	else if (c == 'u')
		return (ft_putu_fd((unsigned int)p, fd));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_fd((unsigned int)p, fd, c));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	string;
	int		i;
	void	*p;
	int		count;

	i = 0;
	count = 0;
	va_start(string, s);
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			count += ft_putchar_fd(s[i++], 1);
		if (s[i++] == '%')
		{	
			if (s[i] != '%')
				p = va_arg(string, void *);
			count += ft_do_it(s[i], p, 1);
			i++;
		}
		else
			break ;
	}
	va_end(string);
	return (count);
}
