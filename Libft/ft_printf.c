/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:33:54 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/14 16:33:54 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (format == NULL)
		return (0);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_handle_conversion(&format, args);
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_handle_conversion(const char **format, va_list args)
{
	int				width;
	t_left_and_zero	laz;

	ft_parse_flags(format, &width, &laz);
	if (**format == 'c')
		return (ft_handle_char(va_arg(args, int), width, laz.left_align,
				laz.zero_pad));
	if (**format == 's')
		return (ft_handle_string(va_arg(args, char *), width, laz.left_align));
	if (**format == 'd' || **format == 'i')
		return (ft_handle_int(va_arg(args, int), width, laz.left_align,
				laz.zero_pad));
	if (**format == 'u')
		return (ft_handle_unsigned(va_arg(args, unsigned int), width,
				laz.left_align, laz.zero_pad));
	if (**format == 'x' || **format == 'X')
		return (ft_handle_hex(va_arg(args, unsigned int), width, laz,
				**format == 'X'));
	if (**format == 'p')
		return (ft_handle_pointer(va_arg(args, void *), width, laz.left_align));
	if (**format == '%')
		return (ft_putchar('%'));
	return (0);
}
