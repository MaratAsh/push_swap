/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:53:05 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 19:55:08 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_dlist	*ft_create_dlist(void *data, t_dlist *prev, t_dlist *next)
{
	t_dlist	*elem;

	elem = malloc(sizeof(t_dlist));
	if (!elem)
		return (NULL);
	elem->content = data;
	elem->next = next;
	elem->prev = prev;
	if (prev)
		prev->next = elem;
	if (next)
		next->prev = elem;
	return (elem);
}
