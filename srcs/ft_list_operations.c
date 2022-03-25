/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:53:05 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 21:36:36 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>
#define STRPREV "  "

static void	ft_print_ptr(void *ptr)
{
	if ((size_t) ptr >= (16 ^ 12))
	{
		printf("  %p  ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 11))
	{
		printf("  %p  ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 10))
	{
		printf("  %p  ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 9))
	{
		printf("   %p  ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 8))
	{
		printf("   %p   ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 7))
	{
		printf("    %p   ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 6))
	{
		printf("     %p   ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 5))
	{
		printf("     %p    ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 6))
	{
		printf("      %p    ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 5))
	{
		printf("      %p     ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 4))
	{
		printf("      %p      ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 3))
	{
		printf("       %p      ", ptr);
	}
	else if ((size_t) ptr >= (16 ^ 2))
	{
		printf("       %p       ", ptr);
	}
	else if ((size_t) ptr >= 16)
	{
		printf("       %p        ", ptr);
	}
	else
	{
		printf("       %p        ", ptr);
	}
}

void	ft_dllist_print(t_dlist *dllist, int rec_depth)
{
	int	i;
	t_data	*data;

	if (!dllist)
	{
		printf("%p\n", dllist);
		return ;
	}
	data = ft_dlstdata(dllist);
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("     |");
	ft_print_ptr(dllist);
	printf("|\n");
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("prev |");
	ft_print_ptr(dllist->prev);
	printf("|\n");
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("next |");
	ft_print_ptr(dllist->next);
	printf("|\n");
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("numbr|  %-14d  |\n", data->number);
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("indx |  %14u  |\n", data->index);
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("group|  %14u  |\n", data->group);
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("     --------------------\n");
	
	if (dllist && dllist->next)
		ft_dllist_print(dllist->next, rec_depth + 1);
}
