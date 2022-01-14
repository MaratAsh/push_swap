/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:53:05 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/14 17:05:16 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*dll_create_element(void *data)
{
	t_stack	*elem;

	elem = (t_stack *) malloc(sizeof(t_stack));
	if (elem)
	{
		elem->prev = NULL;
		elem->next = NULL;
		elem->data = data;
	}
	return (elem);
}

t_stack	*dll_get_last_elem(t_stack *elem)
{
	if (elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

t_stack	*dll_insert_to_last(t_stack *head, t_stack *elem)
{
	t_stack	*last;

	last = dll_get_last_elem(head);
	last->next = elem;
	elem->prev = last;
	return (elem);
}