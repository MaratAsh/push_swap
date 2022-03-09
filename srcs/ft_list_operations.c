/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:53:05 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/09 14:38:27 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>
#define STRPREV "  "

t_stack	*dll_create_element(void *data)
{
	t_stack	*elem;

	elem = (t_stack *) malloc(sizeof(t_stack));
	if (elem)
	{
		elem->prev = NULL;
		elem->next = NULL;
		elem->data = data;
	}
	return (elem);
}

t_stack	*dll_get_last_elem(t_stack *elem)
{
	if (elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

t_stack	*dll_insert_to_last(t_stack *head, t_stack *elem)
{
	t_stack	*last;

	last = dll_get_last_elem(head);
	last->next = elem;
	elem->prev = last;
	return (elem);
}
/*
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

void	ft_dll_print(t_stack *dllist, int rec_depth)
{
	int	i;

	if (!dllist)
	{
		printf("%p\n", dllist);
		return ;
	}
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
	printf("data |");
	ft_print_ptr(dllist->data);
	printf("-> %d |\n", *((int *)dllist->data));
	i = 0;
	while (i++ < rec_depth)
		printf(STRPREV);
	printf("     --------------------\n");
	
	if (dllist && dllist->next)
		ft_dll_print(dllist->next, rec_depth + 1);
}
*/

void	ft_dll_print(t_stack *dllist, int rec_depth)
{
	(void) dllist;
	(void) rec_depth;
}
