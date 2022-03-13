/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 22:40:43 by alcierra         ###   ########.fr       */
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
	t_data	*first;
	t_data	*second;
	t_data	*third;

	if (type == 'a')
	{
		first = ft_dlstdata(all->st_a);
		second = ft_dlstdata(all->st_a->next);
		third = ft_dlstdata(all->st_a->next->next);
	}
	else
	{
		first = ft_dlstdata(all->st_b);
		second = ft_dlstdata(all->st_b->next);
		third = ft_dlstdata(all->st_b->next->next);
	}
	if (first->index > second->index && first->index < third->index
		&& second->index < third->index)
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
	else if (first->index > second->index && first->index > third->index
		&& second->index > third->index)
	{
		if (type == 'a')
		{
			ft_putendl_fd("sa", 1);
			ft_operation_swap_a(all);
			ft_putendl_fd("rra", 1);
			ft_operation_revrotate_a(all);
		}
		else
		{
			ft_putendl_fd("sb", 1);
			ft_operation_swap_b(all);
			ft_putendl_fd("rrb", 1);
			ft_operation_revrotate_b(all);
		}
	}
	else if (first->index > second->index && first->index > third->index
		&& second->index < third->index)
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
	else if (first->index < second->index && first->index < third->index
		&& second->index > third->index)
	{
		if (type == 'a')
		{
			ft_putendl_fd("sa", 1);
			ft_operation_swap_a(all);
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
		}
		else
		{
			ft_putendl_fd("sb", 1);
			ft_operation_swap_b(all);
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
	}
	else if (first->index < second->index && first->index > third->index
		&& second->index > third->index)
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

void	ft_swipe(t_all *all, char type)
{
	(void) all;
	(void) type;
}

void	ft_push_a_all(t_all *all)
{
	unsigned int	min;

	while (all->st_b)
	{
		min = ft_dlst_mindata(all->st_b)->index;
		while (ft_dlstdata(all->st_b)->index != min)
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
		ft_putendl_fd("pa", 1);
		ft_operation_push_a(all);

		ft_putendl_fd("ra", 1);
		ft_operation_rotate_a(all);
	}
}

void	ft_sort_b_(t_all *all)
{
	size_t			count;
	size_t			pushed;
	size_t			i;
	unsigned int	min;
	unsigned int	mid;

	count = ft_dlstsize(all->st_b);
	pushed = 0;
	min = ft_dlst_mindata(all->st_b)->index;
	mid = count / 2 + min;
	i = 0;
	while (i < count)
	{
		if (ft_dlstdata(all->st_b)->index > mid)
		{
			ft_putendl_fd("pa", 1);
			ft_operation_push_a(all);
			pushed++;
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
		i++;
	}
	i = 0;
	while (i < pushed)
	{
		ft_putendl_fd("pb", 1);
		ft_operation_push_b(all);
		i++;
	}
}

void	ft_sort_b(t_all *all)
{
	size_t	count;
	size_t	i;
	size_t	mid;
	t_dlist	*curr;
	t_data	*data;

	count = ft_dlstsize(all->st_b);
	if (count < 3)
	{
		ft_2_sort(all, 'b');
		return ;
	}
	else if (count < 50)
	{
		//ft_sort_b_(all);
		ft_push_a_all(all);
		return ;
	}
	mid = count / 2 + ft_dlst_mindata(all->st_b)->index;
	curr = all->st_b;
	i = 0;
	while (i < count)
	{
		data = ft_dlstdata(curr);
		if (data->index > mid)
		{
			ft_putendl_fd("pa", 1);
			ft_operation_push_a(all);
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
		curr = all->st_b;
		i++;
	}
	ft_sort_b(all);
	/*
	curr = all->st_b;
	while (curr)
	{
		ft_dlstdata(curr)->group++;
		curr = curr->next;
	}
	
	while (all->st_b)
	{
		ft_putendl_fd("pb", 1);
		ft_operation_push_a(all);
	}
	*/
}

void	ft_sort_a(t_all *all)
{
	size_t	count;
	size_t	i;
	size_t	mid;
	t_dlist	*curr;
	//t_dlist	*stop;
	t_data	*data;

	count = ft_dlstsize(all->st_a);
	mid = count / 2 + ft_dlst_mindata(all->st_a)->index;
	curr = all->st_a;
	i = 0;
	while (i < count)
	{
		data = ft_dlstdata(curr);
		if (data->index < mid)
		{
			data->group++;
			ft_putendl_fd("pb", 1);
			ft_operation_push_b(all);
		}
		else
		{
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
		}
		curr = all->st_a;
		i++;
	}
	ft_sort_b(all);
}

void	ft_quick_sort_b(t_all *all)
{
	size_t			count;
	size_t			i;
	unsigned int	middle;

	count = ft_dlstsize(all->st_b);
	if (count == 2)
	{
		ft_2_sort(all, 'b');
		return ;
	}
	else if (count == 3)
	{
		ft_3_sort(all, 'b');
		return ;
	}
	middle = count / 2 + ft_dlst_mindata(all->st_b)->index;
	i = 0;
	while (i < count)
	{
		if (ft_dlstdata(all->st_b)->index >= middle)
		{
			ft_putendl_fd("pa", 1);
			ft_operation_push_a(all);
			//ft_putendl_fd("ra", 1);
			//ft_operation_rotate_a(all);
		}
		else
		{
			ft_putendl_fd("rb", 1);
			ft_operation_rotate_b(all);
		}
		i++;
	}
	ft_quick_sort_b(all);
}

static void	ft_stack_a_middle_norm(t_all *all, unsigned int middle, size_t *ptr)
{
	if (ft_dlstdata(all->st_a)->index < middle)
	{
		ft_putendl_fd("pb", 1);
		ft_operation_push_b(all);
		(*ptr)++;
	}
	else
	{
		ft_putendl_fd("ra", 1);
		ft_operation_rotate_a(all);
	}
}

void	ft_stack_a_middle(t_all *all)
{
	unsigned int	middle;
	size_t			count;
	size_t			i;
	size_t			pushed;

	count = ft_dlstsize(all->st_a);
	middle = count / 2;
	i = 1;
	pushed = 0;
	while (i < count)
	//while (i < count && pushed < count / 2)
	{
		ft_stack_a_middle_norm(all, middle, &pushed);
		i++;
	}
}
