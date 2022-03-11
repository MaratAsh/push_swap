/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:59:33 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 16:46:36 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void*))
{
	t_dlist	*start;

	if (*dlst)
		return ;
	start = *dlst;
	while (start && start->prev)
		start = start->prev;
	while (start)
	{
		start = start->next;
		if (del)
			del(start->prev->content);
		free(start->prev);
	}
	*dlst = NULL;
}
