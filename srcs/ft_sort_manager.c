/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:44:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 21:47:17 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

size_t	ft_distance(t_dlist *dlist, unsigned int index)
{
	size_t	distance;

	distance = 0;
	while (dlist && ft_dlstdata(dlist)->index != index)
	{
		dlist = dlist->next;
		distance++;
	}
	return (distance);
}

void	ft_sort_manager(t_all *all)
{
	size_t	count;
	unsigned int current_group;
	t_data	*data;

	if (ft_is_sorted(all->st_a))
		return ;
	count = ft_dlstsize(all->st_a);
	if (count == 2)
		ft_2_sort(all, 'a');
	else if (count == 3)
		ft_3_sort(all, 'a');
	else if (count > 3)
	{
		ft_big_sort(all);
		return ;
		
		ft_stack_a_middle(all);
		(void) current_group;
		/*
		ft_quick_sort_b(all);
		data = ft_dlstdata(all->st_a);
		current_group = data->group;
		while (current_group > 0 || ft_dlstdata(all->st_a->next)->group > 0)
		{
			while (data && data->group == current_group)
			{
				ft_operation_push_b(all);
				ft_putendl_fd("pb", 1);
				if (all->st_a)
					data = ft_dlstdata(all->st_a);
				else
					break ;
			}
			ft_quick_sort_b(all);
			if (!(all->st_a))
				break ;
			data = ft_dlstdata(all->st_a);
			current_group = data->group;
		}
		data = ft_dlstdata(all->st_a);
		while (data->index != 0)
		{
			ft_operation_push_b(all);
			ft_putendl_fd("pb", 1);
			data = ft_dlstdata(all->st_a);
		}
		ft_quick_sort_b(all);
		data = ft_dlstdata(all->st_a);
		current_group = data->group;
		while (current_group > 0 || ft_dlstdata(all->st_a->next)->group > 0)
		{
			while (data && data->group == current_group)
			{
				ft_operation_push_b(all);
				ft_putendl_fd("pb", 1);
				if (all->st_a)
					data = ft_dlstdata(all->st_a);
				else
					break ;
			}
			ft_quick_sort_b(all);
			if (!(all->st_a))
				break ;
			data = ft_dlstdata(all->st_a);
			current_group = data->group;
		}*/
	}
	unsigned int	index_curr;
	unsigned int	count_for;
	t_dlist			*dlist;

	if (ft_is_sorted(all->st_a))
	{
		ft_putendl_fd("sorted", 1);
		return ;
	}
	else
		return ;
	
	index_curr = ft_dlstsize(all->st_a) - 1;
	dlist = ft_dlst_mindata_dlst(all->st_a);
	(void) data;
	(void) count_for;
	
	while (all->st_a)
	{
		data = ft_dlstdata(all->st_a);
		dlist = all->st_a;
		count_for = 0;
		printf("%p->data = %p\n", dlist, data);
		count_for = ft_distance(dlist, index_curr);
		printf("dlst size:	%lu\ndistance = %u\n", ft_dlstsize(all->st_a), count_for);
		if (ft_dlstsize(all->st_a) / 2 < count_for)
		{
			if (index_curr == data->index)
			{
				ft_operation_push_b(all);
				ft_putendl_fd("pb", 1);
				index_curr--;
			}
			else
			{
				ft_operation_revrotate_a(all);
				ft_putendl_fd("rra", 1);
			}
			continue ;
		}
		printf("aaaaaa 2\n");
		if (index_curr == data->index)
		{
			printf("aaaaaa 3\n");
			ft_operation_push_b(all);
			ft_putendl_fd("pb", 1);
			index_curr--;
		}
		else
		{
			printf("aaaaaa 3.2\n");
			ft_operation_rotate_a(all);
			ft_putendl_fd("ra", 1);
		}
		printf("aaaaaa 4\n");
	}
	while (all->st_b)
	{
		ft_operation_revrotate_b(all);
		ft_operation_push_a(all);
		ft_putendl_fd("rrb", 1);
		ft_putendl_fd("pa", 1);
	}
}
/*
void	ft_sort_manager(t_all *all)
{
	unsigned int	index_curr;
	t_data			*data;
	t_dlist			*dlist;

	index_curr = ft_dlstsize(all->st_a) - 1;
	dlist = ft_dlst_mindata_dlst(all->st_a);
	while (all->st_a)
	{
		data = ft_dlstdata(all->st_a);
		if (index_curr == data->index)
		{
			ft_operation_push_b(all);
			ft_putendl_fd("pb", 1);
			index_curr--;
		}
		else
		{
			ft_operation_rotate_a(all);
			ft_putendl_fd("ra", 1);
		}
	}
	while (all->st_b)
	{
		ft_operation_revrotate_b(all);
		ft_operation_push_a(all);
		ft_putendl_fd("rrb", 1);
		ft_putendl_fd("pa", 1);
	}
}
*/