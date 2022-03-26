/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:27:54 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 11:54:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_stack_b_push_to_a(t_all *all)
{
	t_data	*data;

	while (all->st_b)
	{
		data = ft_dlstdata(all->st_a);
		data->group = 0;
		ft_operation_push_a(all);
		ft_operation_rotate_a(all);
		ft_putendl_fd("pa", 1);
		ft_putendl_fd("ra", 1);
	}
}

void	ft_quick_sort_b(t_all *all)
{
	size_t			count;
	size_t			i;
	unsigned int	middle;
	t_data			*data;

	count = ft_dlstsize(all->st_b);
	if (count == 1)
		ft_stack_b_push_to_a(all);
	else if (count == 2)
	{
		ft_2_sort(all, 'b');
		ft_stack_b_push_to_a(all);
		return ;
	}
	else if (count == 3)
	{
		ft_3_sort(all, 'b');
		ft_stack_b_push_to_a(all);
		return ;
	}
	middle = count / 2 + ft_dlst_mindata(all->st_b)->index;
	i = 0;
	while (i < count)
	{
		data = ft_dlstdata(all->st_b);
		if (data->index > middle)
		{
			data->group++;
			ft_putendl_fd("pa", 1);
			ft_operation_push_a(all);
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
		i++;
	}
	ft_stack_group_add(all->st_b);
	ft_quick_sort_b(all);
}
