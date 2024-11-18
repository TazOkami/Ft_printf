/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <Jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:27:38 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/18 09:20:29 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	char	*str ;
	int		count;

	str = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count = ft_putptr(n / 16);
		if (count < 0)
			return (-1);
	}
	if (ft_putchar(str[n % 16]) < 0)
		return (-1);
	return (count + 1);
}

int	ft_handle_pointer(va_list args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	count += ft_putptr((unsigned long)ptr);
	return (count);
}
