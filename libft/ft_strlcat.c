/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:11:37 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/17 15:48:07 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	isrc;
	char	*s;	

	idst = 0;
	isrc = 0;
	s = (char *)src;
	while (dst[idst] != '\0' && idst < dstsize)
		idst++;
	while (s[isrc] != '\0' && idst + isrc + 1 < dstsize)
	{
		dst[idst + isrc] = src[isrc];
		isrc++;
	}
	if (idst < dstsize)
		dst[idst + isrc] = '\0';
	return (idst + ft_strlen(s));
}
