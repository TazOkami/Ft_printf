/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:18:17 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 09:58:03 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count = ft_putnbr_hex(n / 16, uppercase);
		if (count < 0)
			return (-1);
	}
	if (uppercase)
		c = ("0123456789ABCDEF"[n % 16]);
	else
		c = ("0123456789abcdef"[n % 16]);
	if (ft_putchar(c) < 0)
		return (-1);
	return (count + 1);
}

int	ft_handle_hex_lowercase(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_hex(n, 0));
}

int	ft_handle_hex_uppercase(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_hex(n, 1));
}
