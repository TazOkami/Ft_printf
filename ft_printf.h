/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:57:08 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/11/02 09:26:59 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_decimal(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hex_lowercase(va_list args);
int		ft_handle_hex_uppercase(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
#endif
