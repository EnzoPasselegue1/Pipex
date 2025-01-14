/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:31:40 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/14 11:31:40 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

//////STRUCT//////
typedef struct s_left_and_zero
{
	int		left_align;
	int		zero_pad;
}			t_left_and_zero;

//////MAIN///////
int		ft_printf(const char *format, ...);
int		ft_handle_conversion(const char **format, va_list args);

//////PARSING//////
void	ft_parse_flags(const char **format, int *width, t_left_and_zero *laf);
void	ft_handle_padding(int width, int len, int left_align, int zero_pad);

//////LEN//////
int		ft_strlen(const char *str);
int		ft_ptrlen(uintptr_t ptr);
int		ft_numlen_hex(unsigned int num);
int		ft_numlen(int n);

//////PUT//////
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnstr(char *str, int n);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(uintptr_t num, int is_uppercase);
int		ft_putptr(uintptr_t ptr);

//////HANDLE//////
int		ft_handle_char(char c, int width, int left_align, int zero_pad);
int		ft_handle_string(char *str, int width, int left_align);
int		ft_handle_int(int num, int width, int left_align, int zero_pad);
int		ft_handle_unsigned(unsigned int num, int width, int left_align,
			int zero_pad);
int		ft_handle_pointer(void *ptr, int width, int left_align);
int		ft_handle_hex(unsigned int num, int width, t_left_and_zero laf,
			int is_uppercase);

#endif