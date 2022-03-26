/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:29:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 15:37:19 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

unsigned int	ft_min_group(t_dlist *dlist)
{
	unsigned int	group;
	t_data			*data;

	data = ft_dlstdata(dlist);
	if (!data)
		return (0);
	group = data->group;
	while (dlist && data)
	{
		if (data->group < group)
			group = data->group;
		dlist = dlist->next;
		data = ft_dlstdata(dlist);
	}
	return (group);
}

void	ft_sort__b(t_all *all)
{
	size_t			count;
	t_data			*data;
	t_data			*min_data;
	unsigned int	middle;
	//unsigned int	min_group;
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
		// min_group = ft_min_group(all->st_b);
		while (i < count)
		{
			data = ft_dlstdata(all->st_b);
			if (data->index >= middle)
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
		ft_sort__b(all);
	}
}

void	ft_push_b_greater_group(t_all *all)
{
	t_data			*data;
	unsigned int	group;

	data = ft_dlstdata(all->st_a);
	group = data->group;
	while (data && data->group == group)
	{
		ft_putendl_fd("pb", 1);
		ft_operation_push_b(all);
		data = ft_dlstdata(all->st_a);
	}
}

void	ft_push_n_groups(t_all *all, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_push_b_greater_group(all);
		i++;
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
	while (data && data->index != 0)
	{
		ft_push_n_groups(all, 1);
		ft_sort__b(all);
		group = data->group;
		data = ft_dlstdata(all->st_a);
	}
}
