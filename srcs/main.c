/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:13 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/06 18:23:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*nums;
	t_all	*data;

	if (argc <= 1)
		return (0);
	if (ft_check_dublicates(argv + 1, argc - 1) == 0)
	{
		ft_putendl_fd("dublicates was found", 1);
		return (0);
	}
	if (ft_check_ints_only(argv + 1, argc - 1) == 0)
	{
		ft_putendl_fd("not only int values was found", 1);
		return (0);
	}
	nums = ft_strs_to_ints(argv + 1, argc - 1);
	data = malloc(sizeof(t_all));
	data->st_a = ft_construct_stack(nums, argc - 1);
	data->st_b = NULL;
	ft_dll_print(data->st_a, 0);
	argc--;
	ft_putendl_fd("-----------------------------------------", 1);
	if (argc == 2)
		ft_2_sort(data, 'a');
	else if (argc == 3)
		ft_3_sort(data, 'a');
	else if (argc == 4 || argc == 5)
		ft_4_5_sort(data);
	else if (5 < argc)
		ft_5_sort(*data);
	ft_putendl_fd("-----------------------------------------", 1);
	ft_putendl_fd("stack a after:", 1);
	ft_dll_print(data->st_a, 0);
	if (data != NULL && data->st_b != NULL)
	{
		ft_putendl_fd("stack b:", 1);
		ft_dll_print(data->st_b, 0);
	}
	ft_stack_free(data->st_a);
	ft_stack_free(data->st_b);
	free(data);
	free(nums);
	return (0);
}
