/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:57:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 20:01:49 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_stack_free(t_dlist *stack)
{
	t_dlist	*next;

	while (stack)
	{
		next = stack->next;
		free(stack->content);
		free(stack);
		stack = next;
	}
}
