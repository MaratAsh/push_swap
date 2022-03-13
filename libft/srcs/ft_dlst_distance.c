/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:22:52 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 20:36:02 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_dlst_distance(t_dlist *start, t_dlist *end)
{
	size_t	distance;

	distance = 0;
	while (start->next)
	{
		start = start->next;
		if (start == end)
			return (distance);
		distance++;
	}
	return (-1);
}

size_t	ft_dlst_distance_to_content(t_dlist *start, void *end)
{
	size_t	distance;

	if (start->content == end)
		return (0);
	distance = 0;
	while (start->next)
	{
		start = start->next;
		if (start->content == end)
			return (distance);
		distance++;
	}
	return (-1);
}
