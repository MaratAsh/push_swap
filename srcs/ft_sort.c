/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 18:45:52 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_2_sort_1greater2_norm(t_all *all, char type)
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
		ft_2_sort_1greater2_norm(all, type);
}

void	ft_5_sort(t_all *all)
{
	(void) all;
}
