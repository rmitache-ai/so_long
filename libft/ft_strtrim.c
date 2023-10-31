/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:04:16 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/18 11:07:19 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_found(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*trimmed;

	start = s1;
	while (*start && is_found(*start, set))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && is_found(*end, set))
		end--;
	len = (end - start) + 1;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, start, len);
	trimmed[len] = '\0';
	return (trimmed);
}
