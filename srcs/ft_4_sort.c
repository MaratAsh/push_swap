/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:02:52 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 12:21:30 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_4_sort(t_all *all)
{
	while (ft_dlstsize(all->st_a) > 3)
	{
		if (((t_data *) all->st_a->content)->index == 0)
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
	ft_3_sort(all, 'a');
	ft_operation_push_a(all);
	ft_putendl_fd("pa", 1);
}
