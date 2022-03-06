/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:07 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 19:47:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_operation_push_a(t_all *stacks)
{
	t_stack	*elem;

	if (stacks->st_b == NULL)
		return ;
	elem = stacks->st_b;
	stacks->st_b = stacks->st_b->next;
	elem->next->prev = NULL;
	elem->next = stacks->st_a;
	if (stacks->st_a != NULL)
		stacks->st_a->prev = elem;
	stacks->st_a = elem;
}

void	ft_operation_push_b(t_all *stacks)
{
	t_stack	*elem;

	if (stacks->st_a == NULL)
		return ;
	elem = stacks->st_a;
	stacks->st_a = stacks->st_a->next;
	elem->next->prev = NULL;
	elem->next = stacks->st_b;
	if (stacks->st_b != NULL)
		stacks->st_b->prev = elem;
	stacks->st_b = elem;
}