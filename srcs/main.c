/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:13 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 16:46:48 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	main(int argc, char **argv)
{
	size_t	count;
	t_dlist	*dlist;

	dlist = ft_convert(argv + 1, argc - 1);
	count = ft_dlstsize(dlist);
	//ft_dllist_print(dlist, 0);
	ft_dlstclear(&dlist, free);
	return (0);
}
