/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:54:31 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 16:27:52 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_stack_print(t_dlist *dlist)
{
	t_data	*data;

	while (dlist)
	{
		data = ft_dlstdata(dlist);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(data->index, 1);
		dlist = dlist->next;
	}
	ft_putstr_fd("\n", 1);
}
