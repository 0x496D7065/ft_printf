/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:15:30 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/29 18:03:23 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_count_digit(unsigned long long value)
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

int	ft_print_buffer(char *str, unsigned long long value, int digit, int len)
{
	const char	*base;

	base = "0123456789abcdef";
	if (value == 0)
	{
		str[2] = '0';
		return (len);
	}
	while (digit >= 2)
	{
		str[digit--] = base[value % 16];
		value /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	while (*str)
	{
		ft_putchar(*str);
		len++;
		str++;
	}
	return (len);
}

int	ft_print_ptr(va_list arg, int len)
{
	char				*buffer;
	void				*ptr;
	int					digit;
	unsigned long long	value;

	ptr = va_arg(arg, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		len += 5;
		return (len);
	}
	value = (unsigned long long)ptr;
	digit = ft_count_digit(value);
	buffer = (char *)malloc((digit + 3) * sizeof(char));
	if (!buffer)
		return (0);
	digit += 1;
	buffer[digit + 1] = '\0';
	len = ft_print_buffer(buffer, value, digit, len);
	free(buffer);
	return (len);
}
