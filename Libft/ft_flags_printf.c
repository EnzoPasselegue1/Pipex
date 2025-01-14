/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:30 by enpassel          #+#    #+#             */
/*   Updated: 2024/11/15 09:52:39 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(const char **format, int *width, t_left_and_zero *laz)
{
	laz->left_align = 0;
	laz->zero_pad = 0;
	*width = 0;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			laz->left_align = 1;
		if (**format == '0')
			laz->zero_pad = 1;
		(*format)++;
	}
}

void	ft_handle_padding(int width, int len, int left_align, int zero_pad)
{
	char	pad_char;

	if (left_align)
		return ;
	pad_char = zero_pad;
	if (zero_pad)
		pad_char = '0';
	else
		pad_char = ' ';
	while (width-- > len)
		ft_putchar(pad_char);
}
