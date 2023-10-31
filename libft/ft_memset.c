/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:47:09 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/18 10:52:10 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned int	counter;
	unsigned char	*p;

	counter = 0;
	p = (unsigned char *)str;
	while (counter < len)
	{
		p[counter] = c;
		counter++;
	}
	return (str);
}
