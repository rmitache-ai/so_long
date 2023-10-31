/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:49:38 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/18 10:58:56 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	b;
	unsigned int	l;

	b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] && b < len)
	{
		l = 0;
		if (big[b] == little[l])
		{
			while (little[l] == big[b + l] && b + l < len)
			{
				l++;
				if (!little[l])
					return ((char *)&big[b]);
			}
		}
		b++;
	}
	return (0);
}
