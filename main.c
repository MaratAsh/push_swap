/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:13 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/14 15:57:52 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*nums;

	if (argc > 1)
	{
		nums = ft_strs_to_ints(argv + 1, argc - 1);
		// argc--;
		int i = -1;
		while (++i < argc - 1)
		{
			printf("%d\n", nums[i]);
			// --argc;
		}
	}
	return (0);
}
