/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:51:48 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/29 17:54:39 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_str(va_list arg, int len)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		len += 6;
		return (len);
	}
	while (*s)
	{
		ft_putchar(*s);
		len++;
		s++;
	}
	return (len);
}

int	ft_print_nbr10(int n, int len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		len += 1;
	}
	if (n >= 10)
		len = ft_print_nbr10((n / 10), len);
	ft_putchar(((n % 10) + '0'));
	len++;
	return (len);
}

int	ft_print_u10(unsigned int n, int len)
{
	if (n >= 10)
		len = ft_print_u10((n / 10), len);
	ft_putchar(((n % 10) + '0'));
	len++;
	return (len);
}
