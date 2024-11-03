/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:57:27 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 09:12:09 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_handle_char(args));
	if (format == 's')
		return (ft_handle_string(args));
	if (format == 'p')
		return (ft_handle_pointer(args));
	if (format == 'd' || format == 'i')
		return (ft_handle_decimal(args));
	if (format == 'u')
		return (ft_handle_unsigned(args));
	if (format == 'x')
		return (ft_handle_hex_lowercase(args));
	if (format == 'X')
		return (ft_handle_hex_uppercase(args));
	if (format == '%')
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_handle_format(const char **format, va_list args)
{
	int	result;

	if (**format == '%')
	{
		(*format)++;
		result = ft_process_format(**format, args);
		if (result < 0)
			return (-1);
	}
	else
	{
		result = ft_putchar(**format);
		if (result < 0)
			return (-1);
	}
	(*format)++;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		result;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		result = ft_handle_format(&format, args);
		if (result < 0)
		{
			va_end(args);
			return (-1);
		}
		count += result;
	}
	va_end(args);
	return (count);
}
