/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:07 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/14 19:09:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_operation_push(t_stack *s_from, t_stack *s_to)
{
	s_to->prev = s_from;
	s_from->next->prev = NULL;
}

void	ft_operation_push_a(t_all *stacks)
{
	ft_operation_push(stacks->st_a, stacks->st_b);
	stacks->st_a = stacks->st_a
}

void	ft_operation_push_a(t_all *stacks)
{
		
}