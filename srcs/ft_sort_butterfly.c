/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_butterfly.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:09:06 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 11:07:58 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_sort_butterfly_start(t_all *all);
static void	ft_sort_butterfly_end(t_all *all);

void	ft_sort_butterfly(t_all *all)
{
	ft_sort_butterfly_start(all);
	ft_sort_butterfly_end(all);
}

static unsigned int	ft_calc_n(t_dlist *dlist)
{
	size_t	count;

	count = ft_dlstsize(dlist);
	if (count <= 15)
		return (5);
	else if (count <= 50)
		return (10);
	else if (count <= 100)
		return (15);
	else if (count <= 100)
		return (20);
	else if (count <= 200)
		return (25);
	else if (count <= 300)
		return (30);
	else if (count <= 400)
		return (35);
	else if (count <= 500)
		return (40);
	else if (count <= 1000)
		return (50);
	return (60 + count % 1000 * 2);
}

static void	ft_sort_butterfly_start_norm(t_all *all,
				t_data *data, unsigned int *counter_ptr)
{
	if (data->index <= *counter_ptr)
	{
		ft_operation_push_b(all);
		ft_operation_rotate_b(all);
		ft_putendl_fd("pb\nrb", 1);
		(*counter_ptr)++;
	}
	else if (data->index <= *counter_ptr + ft_calc_n(all->st_b))
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

static void	ft_sort_butterfly_start(t_all *all)
{
	unsigned int	counter;
	t_data			*data;

	counter = 0;
	while (all->st_a)
	{
		data = ft_dlstdata(all->st_a);
		ft_sort_butterfly_start_norm(all, data, &counter);
	}
}

static void	ft_sort_butterfly_end(t_all *all)
{
	while (all->st_b)
		ft_push_a_max_b(all);
}
