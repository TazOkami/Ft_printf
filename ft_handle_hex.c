/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:18:17 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/31 15:53:28 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	c;

	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	if (uppercase)
		c = ("0123456789ABCDEF"[n % 16]);
	else
		c = ("0123456789abcdef"[n % 16]);
	write(1, &c, 1);
}

int	ft_handle_hex_lowercase(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_putnbr_hex(value, 0);
	return (ft_count_hex_digits(value));
}

int	ft_handle_hex_uppercase(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_putnbr_hex(value, 1);
	return (ft_count_hex_digits(value));
}
