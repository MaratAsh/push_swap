/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:50:42 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 18:41:43 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_3_sort_get(t_dlist *head, t_data **first_ptr,
			t_data **second_ptr, t_data **third_ptr)
{
	if (head)
	{
		*first_ptr = ft_dlstdata(head);
		if (head->next)
		{
			*second_ptr = ft_dlstdata(head->next);
			if (head->next->next)
				*third_ptr = ft_dlstdata(head->next->next);
		}
	}
}

void	ft_3_sort(t_all *all, char type)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;

	if (type == 'a')
		ft_3_sort_get(all->st_a, &first, &second, &third);
	else
		ft_3_sort_get(all->st_b, &first, &second, &third);
	if (first->index > second->index && first->index < third->index
		&& second->index < third->index)
		ft_3_sort_case_1(all, type);
	else if (first->index > second->index && first->index > third->index
		&& second->index > third->index)
		ft_3_sort_case_2(all, type);
	else if (first->index > second->index && first->index > third->index
		&& second->index < third->index)
		ft_3_sort_case_3(all, type);
	else if (first->index < second->index && first->index < third->index
		&& second->index > third->index)
		ft_3_sort_case_4(all, type);
	else if (first->index < second->index && first->index > third->index
		&& second->index > third->index)
		ft_3_sort_case_5(all, type);
}
