/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:53:51 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/09 13:36:06 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

int	ft_insert(void *data)
{
	return (*((int *) data));
}

int	ft_is_sorted(t_stack *st)
{
	while (st->next)
	{
		if (ft_insert(st->data) > ft_insert(st->next->data))
			return (0);
		st = st->next;
	}
	return (1);
}

static t_all	*ft_create(int *nums, int count)
{
	t_all	*data;

	data = malloc(sizeof(t_all));
	data->st_a = ft_construct_stack(nums, count);
	data->st_b = NULL;
	return (data);
}

int	main(int argc, char **argv)
{
	int		*nums;
	t_all	*data;

	if (argc <= 1)
		return (0);
	if (ft_check_dublicates(argv + 1, argc - 1) == 0)
		return (0);
	if (ft_check_ints_only(argv + 1, argc - 1) == 0)
		return (0);
	nums = ft_strs_to_ints(argv + 1, argc - 1);
	data = ft_create(nums, argc - 1);
	ft_process_input(data);
	if (data->st_b == NULL && ft_is_sorted(data->st_a) == 1)
	{
		ft_putendl_fd("\x1B[92mOK\033[0m", 1);
	}
	else
		ft_putendl_fd("\x1B[31mKO\033[0m", 1);
	ft_stack_free(data->st_a);
	ft_stack_free(data->st_b);
	free(data);
	free(nums);
	return (0);
}
