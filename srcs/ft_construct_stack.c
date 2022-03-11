/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:12:12 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 21:49:15 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>

static unsigned int	ft_get_index(int *nums, unsigned int count, int value)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		if (nums[i] == value)
			return (i);
		i++;
	}
	return (0);
}

t_stack	*ft_construct_stack(int	*nums, int *sorted, unsigned int count)
{
	t_stack			*start;
	t_stack			*current;
	unsigned int	index;
	int				*ptr_curr;

	start = dll_create_element(nums);
	current = start;
	current->index = ft_get_index(sorted, count, *nums);
	current->group = 0;
	index = 1;
	while (index < count)
	{
		ptr_curr = nums + index;
		current->next = dll_create_element(ptr_curr);
		current->index = ft_get_index(sorted, count, *ptr_curr);
		current->group = 0;
		current->next->prev = current;
		current = current->next;
		++index;
	}
	current->index = ft_get_index(sorted, count, *nums);
	current->group = 0;
	return (start);
}
