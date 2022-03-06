/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:53:51 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/06 20:34:39 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"
#include <unistd.h>

#define BUFFER_SIZE 8

static char *gnl(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	size_t		buff_len;
	int			ret;
	char		*nls;
	char		*str;

	buff_len = ft_strlen(buff);
	if (buff_len > 0)
	{
		nls = ft_strchr(buff, '\n');
		if (nls)
		{
			str = malloc(nls - buff + 1);
			str[nls - buff] = 0;
			ft_memcpy(str, buff, nls - buff);
			ft_memmove(buff, nls + 1, BUFFER_SIZE);
			return (str);
		}
	}
	write(1, "> ", 2);
	ret = read(fd, buff + buff_len, BUFFER_SIZE - buff_len);
	if (ret < 0)
		return (NULL);
	buff[buff_len + ret] = 0;
	nls = ft_strchr(buff, '\n');
	if (nls)
	{
		str = malloc(nls - buff + 1);
		str[nls - buff] = 0;
		ft_memcpy(str, buff, nls - buff);
		ft_memmove(buff, nls + 1, BUFFER_SIZE);
		return (str);
	}
	else
	{
		str = malloc(BUFFER_SIZE + 1);
		str[BUFFER_SIZE] = 0;
		ft_memcpy(str, buff, BUFFER_SIZE);
		ft_memset(buff, 0, BUFFER_SIZE);
		return (str);
	}
}

int	main(int argc, char **argv)
{
	int		*nums;
	t_all	*data;
	char	*input;

	if (argc <= 1)
		return (0);
	if (ft_check_dublicates(argv + 1, argc - 1) == 0)
		return (0);
	if (ft_check_ints_only(argv + 1, argc - 1) == 0)
		return (0);
	nums = ft_strs_to_ints(argv + 1, argc - 1);
	data = malloc(sizeof(t_all));
	data->st_a = ft_construct_stack(nums, argc - 1);
	data->st_b = NULL;
	ft_dll_print(data->st_a, 0);
	input = gnl(1);
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
		free(input);
		input = gnl(1);
	}
	ft_putendl_fd("stack a after:", 1);
	ft_dll_print(data->st_a, 0);
	ft_putendl_fd("stack b after:", 1);
	ft_dll_print(data->st_b, 0);
	ft_stack_free(data->st_a);
	ft_stack_free(data->st_b);
	free(data);
	free(nums);
	return (0);
}
