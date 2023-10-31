/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:44:08 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/18 11:08:20 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	size_t	size_sub;
	char	*mem;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size_sub = ft_strlen(s) - start;
	if (size_sub < len)
		len = size_sub;
	mem = (char *)malloc(len + 1 * sizeof(char));
	if (mem == NULL)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		mem[counter] = s[start + counter];
		counter++;
	}
	mem[counter] = '\0';
	return (mem);
}
