/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coincedence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:18:04 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 19:18:35 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_check_coincedence(int *nums, size_t count, int value)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (nums[i] == value)
			return (1);
		i++;
	}
	return (0);
}
