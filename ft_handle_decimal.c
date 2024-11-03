/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:06:29 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 09:26:15 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr(int n)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		num = -num;
		if (ft_putchar('-') < 0)
			return (-1);
	}
	if (num > 9)
		if (ft_putnbr(num / 10) < 0)
			return (-1);
	c = (num % 10) + '0';
	return (ft_putchar(c));
}

int	ft_handle_decimal(va_list args)
{
	int	value;

	value = va_arg(args, int);
	if (ft_putnbr(value) < 0)
		return (-1);
	return (ft_count_digits(value));
}
