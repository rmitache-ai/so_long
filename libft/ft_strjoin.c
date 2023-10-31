/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:35:17 by rmitache          #+#    #+#             */
/*   Updated: 2023/07/28 14:03:15 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*copy;

	mem = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mem && s1 && s2)
	{
		copy = mem;
		while (*s1 != '\0')
			*mem++ = *s1++;
		while (*s2 != '\0')
			*mem++ = *s2++;
		*mem = '\0';
	}
	else
		return (NULL);
	return (copy);
}
