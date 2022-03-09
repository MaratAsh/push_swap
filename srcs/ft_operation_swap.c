/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:12 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/09 14:41:21 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_operation_swap_head(t_stack *head)
{
	t_stack	*second;
	t_stack	*third;

	if (!head)
		return ;
	if (!(head->next))
		return ;
	second = head->next;
	if (second->next)
		third = second->next;
	else
		third = NULL;
	second->next = head;
	second->prev = head->prev;
	head->next = third;
	head->prev = second;
}

void	ft_operation_swap(t_stack **head)
{
	ft_operation_swap_head(*head);
	if (((*head)->prev))
		*head = (*head)->prev;
}

void	ft_operation_swap_a(t_all *all)
{
	if (all->st_a)
		ft_operation_swap(&(all->st_a));
}

void	ft_operation_swap_b(t_all *all)
{
	if (all->st_b)
		ft_operation_swap(&(all->st_b));
}

void	ft_operation_swap_s(t_all *all)
{
	if (all->st_a)
		ft_operation_swap(&(all->st_a));
	if (all->st_b)
		ft_operation_swap(&(all->st_b));
}
