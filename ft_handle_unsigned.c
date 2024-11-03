/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:32:20 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 09:51:20 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count = ft_putnbr_unsigned(n / 10);
		if (count < 0)
			return (-1);
	}
	c = (n % 10) + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (count + 1);
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	if (ft_putnbr_unsigned(value) < 0)
		return (-1);
	return (ft_count_digits_unsigned(value));
}
