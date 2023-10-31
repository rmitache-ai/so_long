/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:46:04 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:32 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + 1;
	mem = malloc(len);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = s1[i];
		i++;
	}
	return (mem);
}
