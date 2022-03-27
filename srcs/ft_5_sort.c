/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_5_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:49:43 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 12:25:21 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_5_sort_norm(t_all *all)
{
	t_data	*data;

	ft_3_sort(all, 'a');
	ft_operation_push_a(all);
	ft_putendl_fd("pa", 1);
	ft_operation_push_a(all);
	ft_putendl_fd("pa", 1);
	data = ft_dlstdata(all->st_a->next);
	if (ft_dlstdata(all->st_a)->index > data->index)
	{
		ft_operation_swap_a(all);
		ft_putendl_fd("sa", 1);
	}
}

void	ft_5_sort(t_all *all)
{
	t_data	*data;

	while (ft_dlstsize(all->st_a) > 3)
	{
		data = ft_dlstdata(all->st_a);
		if (data->index == 0 || data->index == 1)
		{
			ft_operation_push_b(all);
			ft_putendl_fd("pb", 1);
		}
		else
		{
			ft_operation_rotate_a(all);
			ft_putendl_fd("ra", 1);
		}
	}
	ft_5_sort_norm(all);
}
