/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:49:55 by rmitache          #+#    #+#             */
/*   Updated: 2023/04/18 10:51:12 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_nod;

	new_nod = (t_list *)malloc(sizeof(t_list));
	if (!new_nod)
		return (NULL);
	new_nod->content = content;
	new_nod->next = NULL;
	return (new_nod);
}
