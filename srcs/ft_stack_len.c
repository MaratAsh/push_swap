/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:51:54 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 20:54:49 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

size_t	ft_stack_len(t_stack *head)
{
	size_t	index;

	index = 1;
	if (!head)
		return (0);
	while (head->next)
	{
		index++;
		head = head->next;
	}
	return (index);
}