/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a_max_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:29:34 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 11:16:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_push_a_max_b_norm(t_all *all, t_dlist *dlist)
{
	while (all->st_b != dlist)
	{
		ft_operation_rotate_b(all);
		ft_putendl_fd("rb", 1);
	}
	ft_operation_push_a(all);
	ft_putendl_fd("pa", 1);
}

void	ft_push_a_max_b(t_all *all)
{
	t_dlist	*dlist;
	size_t	count;

	dlist = ft_dlstdata_max(all->st_b);
	if (!dlist)
		return ;
	count = ft_dlstsize(all->st_b);
	if (ft_dlst_distance(all->st_b, dlist) < count / 2)
		ft_push_a_max_b_norm(all, dlist);
	else
	{
		while (all->st_b != dlist)
		{
			ft_operation_revrotate_b(all);
			ft_putendl_fd("rrb", 1);
		}
		ft_operation_push_a(all);
		ft_putendl_fd("pa", 1);
	}
}
