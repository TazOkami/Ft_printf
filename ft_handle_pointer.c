/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:27:38 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/31 16:41:34 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	char	c;
	char	*str ;

	str = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr(n / 16);
	}
	c = str[n % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		if (write(1, "0x0", 3) < 0)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	ft_putptr((unsigned long)ptr);
	return (2 + ft_count_hex_digits((unsigned long)ptr));
}
