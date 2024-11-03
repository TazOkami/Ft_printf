/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:02:40 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 08:26:12 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (ft_putstr(str));
}
