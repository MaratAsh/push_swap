/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_butterfly_simple.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:09:06 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 09:29:06 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_sort_butterfly_simple_start(t_all *all);
static void	ft_sort_butterfly_simple_end(t_all *all);

void	ft_sort_butterfly_simple(t_all *all)
{
	ft_sort_butterfly_simple_start(all);
	ft_sort_butterfly_simple_end(all);
}

static void	ft_sort_butterfly_simple_start_norm(t_all *all,
				t_data *data, unsigned int *counter_ptr)
{
	if (data->index <= *counter_ptr)
	{
		ft_operation_push_b(all);
		ft_operation_rotate_b(all);
		ft_putendl_fd("pb\nrb", 1);
		(*counter_ptr)++;
	}
	else if (data->index <= *counter_ptr + 1)
	{
		ft_operation_push_b(all);
		ft_putendl_fd("pb", 1);
		(*counter_ptr)++;
	}
	else
	{
		ft_operation_rotate_a(all);
		ft_putendl_fd("ra", 1);
	}
}

static void	ft_sort_butterfly_simple_start(t_all *all)
{
	unsigned int	counter;
	t_data			*data;

	counter = 0;
	while (all->st_a)
	{
		data = ft_dlstdata(all->st_a);
		ft_sort_butterfly_simple_start_norm(all, data, &counter);
	}
}

static void	ft_sort_butterfly_simple_end(t_all *all)
{
	t_dlist			*tail;
	t_data			*tail_data;
	t_data			*data;

	while (all->st_b)
	{
		data = ft_dlstdata(all->st_b);
		tail = ft_dlstlast(all->st_b);
		tail_data = ft_dlstdata(tail);
		if (data->index >= tail_data->index)
		{
			ft_operation_push_a(all);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			ft_operation_revrotate_b(all);
			ft_operation_push_a(all);
			ft_putendl_fd("rrb\npa", 1);
		}
	}
}
