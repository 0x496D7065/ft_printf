/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:36 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/26 18:56:26 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>

static int	ft_choose_function(va_list arg, char c, int len)
{
	int	n;

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
	{
		n = va_arg(arg, int);
		len = ft_print_nbr10(n, len);
	}
	/*if (c == 'u')
		len = ft_print_u10(arg, len);
	if (c == 'x')
		len = ft_print_hexa_low(arg, len);
	if (c == 'X')
		len = ft_print_hexa_up(arg, len);*/
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

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int a;
	int b;
	char	*ptr = "My name is Jeff";
	
	a = printf("%p\n", ptr);
	b = ft_printf("%p\n", ptr);
	printf("nb str = %d\n", a);
	printf("nb char = %d\n", b);
}
