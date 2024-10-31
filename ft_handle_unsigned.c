/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:32:20 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/31 16:23:19 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static int	ft_count_unsigned_digits(unsigned int n)
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

int	ft_handle_unsigned(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_putnbr_unsigned(value);
	return (ft_count_unsigned_digits(value));
}
