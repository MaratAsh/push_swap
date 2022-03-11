/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:51:36 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:52:06 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

size_t	ft_get_element_index(t_stack *head, int elem)
{
	t_stack	*curr;
	size_t	index;

	index = 1;
	curr = head;
	if ((*(int *)(curr->data)) == elem)
		return (0);
	while (curr->next)
	{
		if ((*(int *)(curr->next->data)) == elem)
			return (index);
		curr = curr->next;
		index++;
	}
	return (0);
}