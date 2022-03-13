/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:53:51 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/13 16:17:55 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*data;

	if (argc <= 1)
		return (0);
	data = ft_create_stacks(argv + 1, argc - 1);
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
	return (0);
}
