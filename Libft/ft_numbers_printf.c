/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:53:11 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/15 09:52:39 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_int(int num, int width, int left_align, int zero_pad)
{
	int	len;

	len = ft_numlen(num);
	if (!left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	len = ft_putnbr(num);
	if (left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	return (len);
}

int	ft_handle_unsigned(unsigned int num, int width, int left_align,
		int zero_pad)
{
	int	len;

	len = ft_numlen(num);
	if (!left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	len = ft_putunbr(num);
	if (left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_handle_hex(unsigned int num, int width, t_left_and_zero laz,
		int is_uppercase)
{
	int	len;

	len = ft_numlen_hex(num);
	if (!laz.left_align && width > len)
		ft_handle_padding(width, len, laz.left_align, laz.zero_pad);
	len = ft_puthex(num, is_uppercase);
	if (laz.left_align && width > len)
		ft_handle_padding(width, len, laz.left_align, laz.zero_pad);
	return (len);
}

int	ft_handle_char(char c, int width, int left_align, int zero_pad)
{
	int	len;

	len = 1;
	if (!left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	ft_putchar(c);
	if (left_align && width > len)
		ft_handle_padding(width, len, left_align, zero_pad);
	if (width > len)
		return (width);
	else
		return (len);
}
