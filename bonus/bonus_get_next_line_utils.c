/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:25:29 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/07 14:26:33 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (mem == 0)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*copy;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
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
