/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:12 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 14:39:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_operation_swap(t_stack *head)
{
	t_stack	*swapable;
	t_stack	*permanent;

	swapable = head->next;
	if (!swapable)
		return ;
	permanent = swapable->next;
	swapable->next = head;
	swapable->prev = head->prev;
	head->next = permanent;
	if (permanent)
		permanent->prev = head;
}
