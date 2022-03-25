/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_sort_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:50:42 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 18:41:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_3_sort_case_1(t_all *all, char type)
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

void	ft_3_sort_case_2(t_all *all, char type)
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

void	ft_3_sort_case_3(t_all *all, char type)
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

void	ft_3_sort_case_4(t_all *all, char type)
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

void	ft_3_sort_case_5(t_all *all, char type)
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
