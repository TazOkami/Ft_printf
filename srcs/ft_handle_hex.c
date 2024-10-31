/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:18:17 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/28 15:24:31 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int n, int fd, int uppercase)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, fd, uppercase);
	if (uppercase)
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
	else
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
}

int	ft_count_hex_digits(uintptr_t n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_handle_hex_lowercase(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_putnbr_hex(value, 1, 0);
	return (ft_count_hex_digits(value));
}

int	ft_handle_hex_uppercase(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_putnbr_hex(value, 1, 1);
	return (ft_count_hex_digits(value));
}
