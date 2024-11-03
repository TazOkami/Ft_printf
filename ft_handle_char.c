/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:51:30 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 08:21:53 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*va_arg est une macro qui extrait le prochain argument de la liste args*/

#include "ft_printf.h"

int	ft_handle_char(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	return (ft_putchar(c));
}
