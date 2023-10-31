/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:11:44 by rmitache          #+#    #+#             */
/*   Updated: 2023/05/15 13:59:34 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned int	counter;
	unsigned char	*p;

	p = (unsigned char *)str;
	counter = 0;
	while (counter < len)
	{
		p[counter] = '\0';
		counter++;
	}
}
