/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:39:14 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 15:12:42 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_hexp(unsigned long input, int *return_value)
{
	if (input >= 16)
	{
		(*return_value)++;
		ft_printf_hexp(input / 16, return_value);
	}
	if (input < 16)
		(*return_value) += 1;
	ft_putchar_fd("0123456789abcdef"[input % 16], 1);
}

void	ft_printf_p(void *p, int *return_value)
{
	ft_putstr_fd("0x", 1);
	(*return_value) += 2;
	ft_printf_hexp((unsigned long)p, return_value);
}
