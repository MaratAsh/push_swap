/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:46:56 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 16:48:21 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_stack_a_middle_norm(t_all *all, unsigned int middle, size_t *ptr)
{
	t_data	*data;

	data = ft_dlstdata(all->st_a);
	if (ft_dlstdata(all->st_a)->index < middle)
	{
		data->group++;
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
	while (i < count && pushed < count / 2)
	{
		ft_stack_a_middle_norm(all, middle, &pushed);
		i++;
	}
}
