/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:44:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 11:18:38 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

size_t	ft_distance(t_dlist *dlist, unsigned int index)
{
	size_t	distance;

	distance = 0;
	while (dlist && ft_dlstdata(dlist)->index != index)
	{
		dlist = dlist->next;
		distance++;
	}
	return (distance);
}

void	ft_sort_manager(t_all *all)
{
	size_t	count;

	if (ft_is_sorted(all->st_a))
		return ;
	count = ft_dlstsize(all->st_a);
	if (count == 2)
		ft_2_sort(all, 'a');
	else if (count == 3)
		ft_3_sort(all, 'a');
	else if (count < 20)
		ft_sort_butterfly_simple(all);
	else if (count > 3)
		ft_sort_butterfly(all);
}
