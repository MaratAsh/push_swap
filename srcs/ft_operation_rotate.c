/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:57:42 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 20:00:42 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_operation_rotate(t_dlist **head)
{
	t_dlist	*first;
	t_dlist	*last;

	first = *head;
	last = first;
	while (last->next)
		last = last->next;
	if (last == first)
		return ;
	first->next->prev = NULL;
	last->next = first;
	first->prev = last;
	*head = first->next;
	first->next = NULL;
}

void	ft_operation_rotate_a(t_all *all)
{
	if (all->st_a)
		ft_operation_rotate(&(all->st_a));
}

void	ft_operation_rotate_b(t_all *all)
{
	if (all->st_b)
		ft_operation_rotate(&(all->st_b));
}

void	ft_operation_rotate_r(t_all *all)
{
	if (all->st_a)
		ft_operation_rotate(&(all->st_a));
	if (all->st_a)
		ft_operation_rotate(&(all->st_b));
}
