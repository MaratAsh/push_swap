/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:59 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 18:41:57 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h>
# include <unistd.h>

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
	t_dlist		*stack_a_tail;
	t_dlist		*stack_b_tail;
}				t_all;

int		*ft_strs_to_ints(char **strs, int count);

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
void	ft_5_sort(t_all *all);

// ft_process_input.c

size_t	ft_process_input(t_all *data);

void	ft_sort_ints(int *nums, size_t count);

/*
	NEW
*/

// ft_list_operations.c

void	ft_dllist_print(t_dlist *dllist, int rec_depth);

// ft_data.c

t_data	*ft_create_data(int number, unsigned int index);
t_data	*ft_dlstdata(t_dlist *dlist);

t_dlist	*ft_convert(char **strs, size_t count);

void	ft_error(void);
size_t	ft_count(void **ptr);
void	ft_free(void **ptr);

t_all	*ft_create_stacks(char **strs, size_t count);

t_data	*ft_dlst_mindata(t_dlist *dlst);
t_dlist	*ft_dlst_mindata_dlst(t_dlist *dlst);

int		ft_is_sorted(t_dlist *st);

void	ft_sort_manager(t_all *all);

void	ft_quick_sort_b(t_all *all);
void	ft_stack_a_middle(t_all *all);

void	ft_3_sort_case_1(t_all *all, char type);
void	ft_3_sort_case_2(t_all *all, char type);
void	ft_3_sort_case_3(t_all *all, char type);
void	ft_3_sort_case_4(t_all *all, char type);
void	ft_3_sort_case_5(t_all *all, char type);

#endif
