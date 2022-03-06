/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/06 17:44:33 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>

void	ft_2_sort(t_all *all, char type)
{
	t_stack	*first;
	t_stack	*second;

	if (type == 'a')
	{
		first = all->st_a;
		second = all->st_a->next;
	}
	else
	{
		first = all->st_b;
		second = all->st_b->next;
	}
	if (*(int *)first->data > *(int *)second->data)
	{
		if (type == 'a')
			ft_putendl_fd("ra", 1);
		else
			ft_putendl_fd("rb", 1);
		first->prev = second;
		first->next = NULL;
		second->next = first;
		second->prev = NULL;
		all->st_a = second;
	}
}

void	ft_3_sort(t_all *all, char type)
{
	int		*first;
	int		*second;
	int		*third;
	int		buff;
	t_stack	*stack;

	if (type == 'a')
		stack = all->st_a;
	else
		stack = all->st_b;
	first = (int *)(stack->data);
	second = (int *)(stack->next->data);
	third = (int *)(stack->next->next->data);
	if (*first > *second && *first > *third)
	{
		if (type == 'a')
			ft_putendl_fd("ra", 1);
		else
			ft_putendl_fd("rb", 1);
		buff = *first;
		*first = *second;
		*second = *third;
		*third = buff;
		ft_3_sort(all, 'a');
	}
	else
	{
		if (*second > *third)
		{
			if (type == 'a')
				ft_putendl_fd("rra", 1);
			else
				ft_putendl_fd("rrb", 1);
			buff = *third;
			*third = *second;
			*second = *first;
			*first = buff;
			ft_3_sort(all, 'a');
		}
		else if (*first > *second)
		{
			if (type == 'a')
				ft_putendl_fd("sa", 1);
			else
				ft_putendl_fd("sb", 1);
			buff = *first;
			*first = *second;
			*second = buff;
		}
	}
}

void	ft_4_5_sort(t_all *all)
{
	t_stack	*curr;
	size_t	count;

	count = 1;
	curr = all->st_a;
	while (curr->next)
	{
		curr = curr->next;
		count++;
	}
	if (*(int *)(all->st_a->data) > *(int *)(curr->data))
	{
		ft_putendl_fd("rra", 1);
		curr->prev->next = NULL;
		curr->prev = NULL;
		curr->next = all->st_a;
		curr->next = all->st_a;
		all->st_a = curr;
		ft_putendl_fd("pb", 1);
		ft_operation_push_b(all);
		if (count > 3)
			ft_4_5_sort(all);
		ft_2_sort(all, 'a');
		//ft_3_sort(all);
	}
}

void	ft_5_sort(t_all all)
{
	(void) all;
}
