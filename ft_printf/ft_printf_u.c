/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:31:07 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 13:55:49 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(unsigned int input, int *return_value, char format)
{
	if (format == 'u')
	{
		ft_putnbr_long(input, 1);
		*return_value += ft_printf_count(input);
	}
	else if (format == 'x')
	{
		ft_printf_hex(input, return_value, format);
	}
	else if (format == 'X')
	{
		ft_printf_hex(input, return_value, format);
	}
}
