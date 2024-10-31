/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:57:08 by Jpaulis           #+#    #+#             */
/*   Updated: 2024/10/28 16:07:38 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_process_format(char format, va_list args);
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_decimal(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hex_lowercase(va_list args);
int		ft_handle_hex_uppercase(va_list args);
int		ft_handle_pointer(va_list args);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_hex(unsigned int n, int fd, int uppercase);
int		ft_putptr_fd(uintptr_t ptr, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_count_digits(int n);
int		ft_count_unsigned_digits(unsigned int n);
int		ft_count_hex_digits(uintptr_t n);

#endif
