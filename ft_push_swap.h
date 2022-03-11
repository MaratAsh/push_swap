/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:59 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 20:33:07 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	void			*data;
	unsigned int	group;
	unsigned int	index;
}				t_stack;

typedef struct s_data
{
	int				number;
	unsigned int	group;
	unsigned int	index;
}				t_data;

typedef struct s_all
{
	t_dlist		*st_a;
	t_dlist		*st_b;
}				t_all;

int		*ft_strs_to_ints(char **strs, int count);

// ft_list_operations.c
t_stack	*dll_create_element(void *data);
t_stack	*dll_get_last_elem(t_stack *elem);
t_stack	*dll_insert_to_last(t_stack *head, t_stack *elem);
void	ft_dll_print(t_stack *dllist, int rec_depth);

// ft_construct_stack.c
t_stack	*ft_construct_stack(int	*nums, int *sorted, unsigned int count);

t_data	*ft_create_data_element(int number, int index);
// ft_operation_push.c

void	ft_operation_push_a(t_all *stacks);
void	ft_operation_push_b(t_all *stacks);

// ft_operation_swap.c

void	ft_operation_swap(t_dlist **head);
void	ft_operation_swap_a(t_all *all);
void	ft_operation_swap_b(t_all *all);
void	ft_operation_swap_s(t_all *all);

// ft_operation_rotate.c

void	ft_operation_rotate(t_dlist **head);
void	ft_operation_rotate_a(t_all *all);
void	ft_operation_rotate_b(t_all *all);
void	ft_operation_rotate_r(t_all *all);

// ft_operation_revrotate.c

void	ft_operation_revrotate(t_dlist **head);
void	ft_operation_revrotate_a(t_all *all);
void	ft_operation_revrotate_b(t_all *all);
void	ft_operation_revrotate_r(t_all *all);

// ft_stack_free.c

void	ft_stack_free(t_dlist *stack);

// ft_arg_checker.c

int		ft_check_dublicates(char **strs_ptr, size_t count);
int		ft_check_ints_only(char **strs_ptr, size_t count);

// ft_sort.c

void	ft_2_sort(t_all *all, char type);
void	ft_3_sort(t_all *all, char type);
void	ft_4_5_sort(t_all *all);
void	ft_5_sort(t_all *all);

// ft_process_input.c

size_t	ft_process_input(t_all *data);

// 

size_t	ft_stack_len(t_stack *head);

void	ft_sort_ints(int *nums, size_t count);

/*
	NEW
*/

void	ft_dllist_print(t_dlist *dllist, int rec_depth);

// ft_data.c

t_data	*ft_create_data(int number, unsigned int index);
t_data	*ft_dlstdata(t_dlist *dlist);

t_dlist	*ft_convert(char **strs, size_t count);

#endif
