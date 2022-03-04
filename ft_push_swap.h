/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:59 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/20 14:44:44 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	void			*data;
}				t_stack;

typedef struct s_all
{
	t_stack		*st_a;
	t_stack		*st_b;
}				t_all;

int		*ft_strs_to_ints(char **strs, int count);

// ft_list_operations.c
t_stack	*dll_create_element(void *data);
t_stack	*dll_get_last_elem(t_stack *elem);
t_stack	*dll_insert_to_last(t_stack *head, t_stack *elem);
void	ft_dll_print(t_stack *dllist, int rec_depth);

// ft_construct_stack.c
t_stack	*ft_construct_stack(int	*nums, int count);

typedef struct s_data
{
	int	number;
	int	index;
}				t_data;

t_data	*ft_create_data_element(int number, int index);

#endif
