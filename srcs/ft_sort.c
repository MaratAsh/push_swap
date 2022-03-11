/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 20:29:42 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>

void	ft_2_sort(t_all *all, char type)
{
	t_dlist	*first;
	t_dlist	*second;
	t_data	*first_data;
	t_data	*second_data;

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
	first_data = (t_data *) first->content;
	second_data = (t_data *) second->content;
	if (first_data->number > second_data->number)
	{
		if (type == 'a')
		{
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
	}
}

void	ft_3_sort(t_all *all, char type)
{
	int		*first;
	int		*second;
	int		*third;
	int		buff;
	t_dlist	*stack;

	if (type == 'a')
		stack = all->st_a;
	else
		stack = all->st_b;
	first = &((t_data *)(stack->content))->number;
	second = &((t_data *)(stack->next->content))->number;
	third = &((t_data *)(stack->next->next->content))->number;
	if (*first > *second && *first > *third)
	{
		if (type == 'a')
		{
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
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
			{
				ft_putendl_fd("rra", 1);
				ft_operation_revrotate_a(all);
			}
			else
			{
				ft_putendl_fd("rrb", 1);
				ft_operation_revrotate_b(all);
			}
			ft_3_sort(all, 'a');
		}
		else if (*first > *second)
		{
			if (type == 'a')
			{
				ft_putendl_fd("sa", 1);
				ft_operation_swap_a(all);
			}
			else
			{
				ft_putendl_fd("sb", 1);
				ft_operation_swap_b(all);
			}
		}
	}
}

void	ft_4_5_sort(t_all *all)
{
	t_dlist	*curr;
	size_t	count;

	count = 1;
	curr = all->st_a;
	while (curr->next)
	{
		curr = curr->next;
		count++;
	}
	if (((t_data *)all->st_a->content)->number > ((t_data *)curr->content)->number)
	{
		ft_putendl_fd("rra", 1);
		ft_operation_revrotate_a(all);
		ft_putendl_fd("pb", 1);
		ft_operation_push_b(all);
		if (count > 3)
			ft_4_5_sort(all);
		ft_2_sort(all, 'a');
	}
}

void	ft_5_sort(t_all *all)
{
	(void) all;
}

size_t	ft_5_sort_(t_all *all)
{
	(void) all;

	return (0);
}
