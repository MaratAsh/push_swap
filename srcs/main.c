/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:13 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 14:38:38 by alcierra         ###   ########.fr       */
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
	nums = ft_strs_to_ints(argv + 1, argc - 1);
	data = malloc(sizeof(t_all));
	data->st_a = ft_construct_stack(nums, argc - 1);
	data->st_b = NULL;
	ft_dll_print(data->st_a, 0);
	
	return (0);
}
