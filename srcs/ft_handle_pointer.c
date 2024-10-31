/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:27:38 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/28 15:48:06 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t n)
{
	char	c;
	char	*str ;

	if (n >= 16)
	{
		ft_putptr(n / 16);
	}
	str = "0123456789abcdef";
	c = str[n % 16];
	write(1, &c, 1);
}

int	ft_handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putptr((uintptr_t)ptr);
	return (2 + ft_count_hex_digits((uintptr_t)ptr));
}
