/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:36 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/29 18:07:25 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>

static int	ft_choose_function(va_list arg, char c, int len)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(arg, int));
		len += 1;
	}
	if (c == 's')
		len = ft_print_str(arg, len);
	if (c == 'p')
		len = ft_print_ptr(arg, len);
	if (c == 'd' || c == 'i')
		len = ft_print_nbr10(va_arg(arg, int), len);
	if (c == 'u')
		len = ft_print_u10(va_arg(arg, unsigned int), len);
	if (c == 'x')
		len = ft_print_hexa(arg, len, 'x');
	if (c == 'X')
		len = ft_print_hexa(arg, len, 'X');
	if (c == '%')
	{
		ft_putchar('%');
		len += 1;
	}
	return (len);
}

static int	ft_vprintf(va_list arg, const char *format, int len)
{
	unsigned char	c;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c = *format;
			len = ft_choose_function(arg, c, len);
			format++;
		}
		else
		{
			c = *format;
			if (c == '\0')
				break ;
			ft_putchar(c);
			format++;
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = ft_vprintf(arg, format, 0);
	va_end(arg);
	return (len);
}
