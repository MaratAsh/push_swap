/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdata_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:49:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 10:43:18 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_dlist	*ft_dlstdata_max(t_dlist *dlist)
{
	t_data			*data;
	unsigned int	max_index;
	t_dlist			*max_index_dlist;

	max_index = 0;
	max_index_dlist = dlist;
	while (dlist)
	{
		data = ft_dlstdata(dlist);
		if (data && data->index > max_index)
		{
			max_index = data->index;
			max_index_dlist = dlist;
		}
		dlist = dlist->next;
	}
	return (max_index_dlist);
}

unsigned int	ft_dlstdata_max_index(t_dlist *dlist)
{
	t_data			*data;
	unsigned int	max_index;
	t_dlist			*max_index_dlist;

	max_index = 0;
	max_index_dlist = dlist;
	while (dlist)
	{
		data = ft_dlstdata(dlist);
		if (data && data->index > max_index)
		{
			max_index = data->index;
			max_index_dlist = dlist;
		}
		dlist = dlist->next;
	}
	return (max_index);
}
