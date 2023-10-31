/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:42:21 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 13:55:35 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_count(long p)
{
	int	i;

	i = 0;
	if (p >= 0 && p <= 9)
		return (1);
	while (p != 0)
	{
		if (p < 0)
		{
			i++;
			p = -p;
		}
		p = p / 10;
		i++;
	}
	return (i);
}