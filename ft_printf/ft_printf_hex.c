/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:39:05 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 14:13:49 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex(unsigned int input, int *return_value, char format)
{
	if (input >= 16)
	{
		(*return_value)++;
		ft_printf_hex(input / 16, return_value, format);
	}
	if (input < 16)
		(*return_value) += 1;
	if (format == 'x')
		ft_putchar_fd("0123456789abcdef"[input % 16], 1);
	if (format == 'X')
		ft_putchar_fd("0123456789ABCDEF"[input % 16], 1);
}
