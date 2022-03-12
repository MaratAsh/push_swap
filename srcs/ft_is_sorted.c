/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:19:03 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 22:19:12 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_is_sorted(t_dlist *st)
{
	while (st->next)
	{
		if (ft_dlstdata(st)->number > ft_dlstdata(st->next)->number)
			return (0);
		st = st->next;
	}
	return (1);
}