/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:18:26 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/09 14:53:43 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"
#include "./get_next_line.h"

static int	ft_process_command(char *input, t_all *data)
{
	if (ft_memcmp(input, "sa", 3) == 0)
		ft_operation_swap_a(data);
	else if (ft_memcmp(input, "sb", 3) == 0)
		ft_operation_swap_b(data);
	else if (ft_memcmp(input, "ss", 3) == 0)
		ft_operation_swap_s(data);
	else if (ft_memcmp(input, "pa", 3) == 0)
		ft_operation_push_a(data);
	else if (ft_memcmp(input, "pb", 3) == 0)
		ft_operation_push_b(data);
	else if (ft_memcmp(input, "ra", 3) == 0)
		ft_operation_rotate_a(data);
	else if (ft_memcmp(input, "rb", 3) == 0)
		ft_operation_rotate_b(data);
	else if (ft_memcmp(input, "rr", 3) == 0)
		ft_operation_rotate_r(data);
	else if (ft_memcmp(input, "rra", 4) == 0)
		ft_operation_revrotate_a(data);
	else if (ft_memcmp(input, "rrb", 4) == 0)
		ft_operation_revrotate_b(data);
	else if (ft_memcmp(input, "rrr", 4) == 0)
		ft_operation_revrotate_r(data);
	else
		return (0);
	return (1);
}

static void	ft_strreplchr(char *str, int key, int value)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned int) str[i] == (unsigned int) key)
			str[i] = (unsigned int) value;
		++i;
	}
}

size_t	ft_process_input(t_all *data)
{
	char	*input;
	size_t	count;

	input = get_next_line(1);
	count = 0;
	while (input)
	{
		if (input[0] == 0)
		{
			free(input);
			break ;
		}
		ft_strreplchr(input, '\n', '\0');
		count += ft_process_command(input, data);
		free(input);
		input = get_next_line(1);
	}
	return (count);
}

/*
size_t	ft_process_input(t_all *data)
{
	char	*input;

	input = get_next_line(1);
	while (input)
	{
		if (input[0] == 0)
		{
			free(input);
			break ;
		}
		if (ft_memcmp(input, "sa", 3) == 0)
		{
			write(1, "make sa\n", 8);
			ft_operation_swap_a(data);
		}
		else if (ft_memcmp(input, "sb", 3) == 0)
		{
			write(1, "make sb\n", 8);
			ft_operation_swap_b(data);
		}
		else if (ft_memcmp(input, "ss", 3) == 0)
		{
			write(1, "make sa&sb\n", 11);
			ft_operation_swap_s(data);
		}
		else if (ft_memcmp(input, "pa", 3) == 0)
		{
			write(1, "make pa\n", 8);
			ft_operation_push_a(data);
		}
		else if (ft_memcmp(input, "pb", 3) == 0)
		{
			write(1, "make pb\n", 8);
			ft_operation_push_b(data);
		}
		else if (ft_memcmp(input, "ra", 3) == 0)
		{
			write(1, "make ra\n", 8);
			ft_operation_rotate_a(data);
		}
		else if (ft_memcmp(input, "rb", 3) == 0)
		{
			write(1, "make rb\n", 8);
			ft_operation_rotate_b(data);
		}
		else if (ft_memcmp(input, "rr", 3) == 0)
		{
			write(1, "make ra&rb\n", 11);
			ft_operation_rotate_r(data);
		}
		else if (ft_memcmp(input, "rra", 4) == 0)
		{
			write(1, "make rra\n", 9);
			ft_operation_revrotate_a(data);
		}
		else if (ft_memcmp(input, "rrb", 4) == 0)
		{
			write(1, "make rrb\n", 9);
			ft_operation_revrotate_b(data);
		}
		else if (ft_memcmp(input, "rrr", 4) == 0)
		{
			write(1, "make rrr\n", 9);
			ft_operation_revrotate_r(data);
		}
		else if (ft_memcmp(input, "print", 5) == 0)
		{
			if (input[6] == 'a')
			{
				ft_putendl_fd("\033[1;32mstack a:\033[0m", 1);
				ft_dll_print(data->st_a, 0);
			}
			else if (input[6] == 'b')
			{
				ft_putendl_fd("\033[1;32mstack b:\033[0m", 1);
				ft_dll_print(data->st_b, 0);
			}
			else
			{
				ft_putendl_fd("\033[1;32mstack a:\033[0m", 1);
				ft_dll_print(data->st_a, 0);
				ft_putendl_fd("\033[1;32mstack b:\033[0m", 1);
				ft_dll_print(data->st_b, 0);
			}
		}
		else if (ft_memcmp(input, "print b", 8) == 0)
		{
			ft_putendl_fd("stack b:", 1);
			ft_dll_print(data->st_b, 0);
		}
		else
		{
			ft_putstr_fd("unknown command: ", 1);
			ft_putendl_fd(input, 1);
		}
		free(input);
		input = get_next_line(1);
	}
	return (1);
}
*/