/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:12:12 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 14:39:44 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_stack	*ft_construct_stack(int	*nums, int count)
{
	t_stack	*start;
	t_stack	*current;
	int		index;

	start = dll_create_element(nums);
	current = start;
	index = 1;
	while (index < count)
	{
		current->next = dll_create_element(nums + index);
		current->next->prev = current;
		current = current->next;
		++index;
	}
	return (start);
}
