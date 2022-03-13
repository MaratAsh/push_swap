/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_mindata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:51:15 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 20:39:10 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_data	*ft_dlst_mindata(t_dlist *dlst)
{
	t_dlist	*min_dl;
	t_data	*min_dt;
	t_dlist	*curr_dl;
	t_data	*curr_dt;

	curr_dl = dlst;
	min_dt = ft_dlstdata(curr_dl);
	while (curr_dl)
	{
		curr_dt = ft_dlstdata(curr_dl);
		if (min_dt->index > curr_dt->index)
		{
			min_dt = curr_dt;
			min_dl = curr_dl;
		}
		curr_dl = curr_dl->next;
	}
	return (min_dt);
}

t_dlist	*ft_dlst_mindata_dlst(t_dlist *dlst)
{
	t_dlist	*min_dl;
	t_data	*min_dt;
	t_dlist	*curr_dl;
	t_data	*curr_dt;

	curr_dl = dlst;
	min_dt = ft_dlstdata(curr_dl);
	while (curr_dl)
	{
		curr_dt = ft_dlstdata(curr_dl);
		if (min_dt->index > curr_dt->index)
		{
			min_dt = curr_dt;
			min_dl = curr_dl;
		}
		curr_dl = curr_dl->next;
	}
	return (min_dl);
}
