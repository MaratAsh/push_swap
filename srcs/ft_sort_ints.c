/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:08:33 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/25 20:01:39 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static size_t	partition(int arr[], size_t low, size_t high)
{
	int		pivot;
	size_t	i;
	size_t	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int arr[], size_t low, size_t high)
{
	size_t	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void	ft_sort_ints(int *nums, size_t count)
{
	size_t	i;

	quick_sort(nums, 1, count - 1);
	i = 0;
	while (i < count - 1)
	{
		if (nums[i] > nums[i + 1])
			swap(nums + i, nums + (i + 1));
		i++;
	}
}
