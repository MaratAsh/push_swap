/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 21:01:35 by alcierra         ###   ########.fr       */
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
	t_data			*min_dt;
	t_dlist			*min_dl;
	size_t			count;
	size_t			i;
	//size_t			distance;
	t_dlist			*curr;
	unsigned int	middle;

	min_dl = ft_dlst_mindata_dlst(all->st_b);
	min_dt = ft_dlstdata(min_dl);
	count = ft_dlstsize(all->st_b);
	//distance = ft_dlst_distance(all->st_b, min_dl);
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
	middle = count / 2 + min_dt->index;
	curr = all->st_b;
	i = 0;
	while (i < count)
	{
		if (ft_dlstdata(curr)->index > middle)
		{
			ft_putendl_fd("pa", 1);
			ft_operation_push_a(all);
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
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

void	ft_stack_a_middle(t_all *all)
{
	unsigned int	middle;
	size_t			count;
	size_t			i;
	size_t			pushed;
	t_dlist			*dlst;

	count = ft_dlstsize(all->st_a);
	dlst = all->st_a;
	middle = count / 2;
	i = 0;
	pushed = 0;
	while (i < count)
	{
		if (ft_dlstdata(dlst)->index < middle)
		{
			ft_putendl_fd("pb", 1);
			ft_operation_push_b(all);
			pushed++;
		}
		else
		{
			ft_putendl_fd("ra", 1);
			ft_operation_rotate_a(all);
		}
	}
}
