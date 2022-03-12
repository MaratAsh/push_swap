/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:44:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 22:47:04 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort_manager(t_all *all)
{
	size_t	count;
	int		i;

	count = ft_dlstsize(all->st_a);
	if (count == 2)
		ft_2_sort(all, 'a');
	else if (count == 3)
		ft_3_sort(all, 'a');
	else if (count > 3)
	{
		i = 0;
		while (ft_is_sorted(all->st_a) == 0 && i < 5)
		{
			ft_sort_a(all);
			i++;
		}
	}
}
