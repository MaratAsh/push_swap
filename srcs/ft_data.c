/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:29:47 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 17:32:16 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_data	*ft_create_data(int number, unsigned int index)
{
	t_data	*elem;

	elem = malloc(sizeof(t_data));
	if (!elem)
		return (NULL);
	elem->index = index;
	elem->number = number;
	elem->group = 0;
	return (elem);
}

t_data	*ft_dlstdata(t_dlist *dlist)
{
	return ((t_data *)(dlist->content));
}
