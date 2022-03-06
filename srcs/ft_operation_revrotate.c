/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_revrotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:57:42 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/06 20:37:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_operation_revrotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*first;

	first = *head;
	last = first;
	while (last->next)
		last = last->next;
	if (last == first)
		return ;
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = first->prev;
	*head = last;
}

void	ft_operation_revrotate_a(t_all *all)
{
	if (all->st_a)
		ft_operation_revrotate(&(all->st_a));
}

void	ft_operation_revrotate_b(t_all *all)
{
	if (all->st_b)
		ft_operation_revrotate(&(all->st_b));
}

void	ft_operation_revrotate_r(t_all *all)
{
	if (all->st_a)
		ft_operation_revrotate(&(all->st_a));
	if (all->st_b)
		ft_operation_revrotate(&(all->st_b));
}
