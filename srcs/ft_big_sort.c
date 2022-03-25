/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:29:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 22:54:07 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort__b(t_all *all)
{
	size_t			count;
	t_data			*data;
	t_data			*min_data;
	unsigned int	middle;
	size_t			i;

	count = ft_dlstsize(all->st_b);
	if (count == 0)
		return ;
	else if (count == 1 || count == 2 || count == 3)
	{
		if (count == 2)
			ft_2_sort(all, 'b');
		else if (count == 3)
			ft_3_sort(all, 'b');
		while (all->st_b)
		{
			data = ft_dlstdata(all->st_b);
			data->group = 0;
			ft_operation_push_a(all);
			ft_putendl_fd("pa", 1);
			ft_operation_rotate_a(all);
			ft_putendl_fd("ra", 1);
		}
		return ;
	}
	else
	{
		min_data = ft_dlst_mindata(all->st_b);
		middle = count / 2 + min_data->index;
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
		ft_sort__b(all);
	}
}

void	ft_big_sort(t_all *all)
{
	t_data			*data;
	unsigned int	group;

	ft_stack_a_middle(all);
	ft_sort__b(all);
	data = ft_dlstdata(all->st_a);
	group = data->group;
	while (data && data->group != 1)
	{
		if (data->group == group)
		{
			ft_putendl_fd("pb", 1);
			ft_operation_push_b(all);
		}
		else
		{
			ft_sort__b(all);
			data = ft_dlstdata(all->st_a);
			group = data->group;
		}
		group = data->group;
		data = ft_dlstdata(all->st_a);
	}
}
