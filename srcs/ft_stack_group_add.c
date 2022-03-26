/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_group_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:53:18 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 11:53:31 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_stack_group_add(t_dlist *stack)
{
	t_data	*data;

	while (stack)
	{
		data = ft_dlstdata(stack);
		data->group++;
		stack = stack->next;
	}
}