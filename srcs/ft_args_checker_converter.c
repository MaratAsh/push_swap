/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker_converter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:42:29 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 15:41:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_end(int *allocated_mem)
{
	ft_putendl_fd("Error", 2);
	free(allocated_mem);
	exit(1);
}

static size_t	ft_str_nums_count(char *str)
{
	size_t	i;
	size_t	count;
	char	is_last_digit;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		count = 1;
	else
		count = 0;
	is_last_digit = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			is_last_digit = 0;
		else
			is_last_digit = 1;
		if (is_last_digit && str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static int	*ft_str_to_ints(char *str)
{
	size_t	i;
	size_t	count;
	size_t	str_len;
	int		num;
	int		*nums;

	count = ft_str_nums_count(str);
	nums = malloc(count * sizeof(int));
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		
	}
}

int	*ft_args_checker_converter(char **strs, size_t count)
{
	size_t	i;
	size_t	j;
	char	*str_inside;
	char	*str_outside;
	size_t	cmp_n;
	
	int		*nums;

	if (count == 0)
		exit(0);
	else if (count == 1)
	{
		
		return (ft_str_to_ints(strs[0]));
	}
	nums = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		str_inside = *(strs + i);
		cmp_n = ft_strlen(str_inside);
		j = i + 1;
		while (j < count)
		{
			str_outside = *(strs + j);
			if (ft_strncmp(str_inside, str_outside, cmp_n
					+ (cmp_n < ft_strlen(str_outside))) == 0)
				ft_alert(nums);
			j++;
		}
		
		i++;
	}
}