/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:20:53 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 14:24:47 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(char *str, int *return_value)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*return_value += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		*return_value += ft_strlen(str);
	}
}
