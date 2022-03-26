/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:49:49 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 17:24:54 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort_insertion_b(t_all *all)
{
	t_dlist			*min_dlist;
	t_data			*min_data;
	unsigned int	distance;
	size_t			count;

	min_dlist = ft_dlst_mindata_dlst(all->st_b);
	min_data = ft_dlstdata(min_dlist);
	distance = ft_dlst_distance(all->st_b, min_dlist);
	count = ft_dlstsize(all->st_b);
	if (count / 2 < distance)
	{
		while (all->st_b != min_dlist)
		{
			ft_operation_revrotate_b(all);
			ft_putendl_fd("rrb", 1);
		}
	}
	else
	{
		while (all->st_b != min_dlist)
		{
			ft_operation_rotate_b(all);
			ft_putendl_fd("rb", 1);
		}
	}
	ft_operation_push_a(all->st_b);
	ft_putendl_fd("pb", 1);
	if (count > 1)
		ft_sort_insertion_b(all);
}
