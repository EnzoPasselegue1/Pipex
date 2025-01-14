/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:26:27 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/14 14:26:01 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(char *str, int width, int left_align)
{
	int	len;

	if (str)
		len = ft_strlen(str);
	else
		len = 6;
	if (!left_align && width > len)
		ft_handle_padding(width, len, left_align, 0);
	len = ft_putnstr(str, len);
	if (left_align && width > len)
		ft_handle_padding(width, len, left_align, 0);
	return (len);
}

int	ft_handle_pointer(void *ptr, int width, int left_align)
{
	int	len;

	len = ft_ptrlen((uintptr_t)ptr);
	if (!left_align && width > len)
		ft_handle_padding(width, len, left_align, 0);
	len = ft_putptr((uintptr_t)ptr);
	if (left_align && width > len)
		ft_handle_padding(width, len, left_align, 0);
	return (len);
}

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	len += ft_putstr("0x");
	len += ft_puthex(ptr, 0);
	return (len);
}

int	ft_puthex(uintptr_t num, int is_uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (is_uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		len += ft_puthex(num / 16, is_uppercase);
	len += ft_putchar(base[num % 16]);
	return (len);
}
