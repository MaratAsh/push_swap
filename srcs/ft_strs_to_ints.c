/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:07:34 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:22 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	*ft_strs_to_ints(char **strs, int count)
{
	int	index;
	int	*nums;

	nums = malloc(count * sizeof(int));
	index = 0;
	while (index < count)
	{
		nums[index] = ft_atoi(strs[index]);
		++index;
	}
	return (nums);
}
