/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:13:11 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 19:21:48 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlstout(t_dlist *elem)
{
	t_dlist	*prev;
	t_dlist	*next;

	if (!elem)
		return (NULL);
	prev = elem->prev;
	next = elem->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
