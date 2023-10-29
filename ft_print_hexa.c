/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:52:37 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/29 18:11:49 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	ft_count_digit(unsigned long long value)
{
	int	digit_count;

	digit_count = 0;
	if (value == 0)
		return (1);
	if (value > 15 && value < 32)
		return (2);
	while ((value / 16) > 1)
	{
		value /= 16;
		digit_count++;
	}
	digit_count++;
	return (digit_count);
}

static int	ft_print_buffer(char *str, unsigned int value, int digit, int x)
{
	const char	*base;
	int			len;

	len = 0;
	if (x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	while (digit >= 0)
	{
		str[digit--] = base[value % 16];
		value /= 16;
	}
	while (*str)
	{
		ft_putchar(*str);
		len++;
		str++;
	}
	return (len);
}

int	ft_print_hexa(va_list arg, int len, int x)
{
	char				*buffer;
	int					digit;
	unsigned int		value;

	value = va_arg(arg, unsigned int);
	digit = ft_count_digit(value);
	buffer = (char *)malloc((digit + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[digit] = '\0';
	digit -= 1;
	len += ft_print_buffer(buffer, value, digit, x);
	free(buffer);
	return (len);
}
