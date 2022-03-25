/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:13 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 20:55:27 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*data;

	data = ft_create_stacks(argv + 1, argc - 1);
	if (!data)
	{
		perror("malloc error");
		return (0);
	}
	ft_sort_manager(data);
	//ft_dllist_print(data->st_a, 0);
	//ft_dllist_print(data->st_b, 0);
	ft_stack_free(data->st_a);
	if (data->st_b)
		ft_stack_free(data->st_b);
	free(data);
	return (0);
}
