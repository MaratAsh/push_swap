/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:41:56 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/06 17:18:56 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_check_dublicates(char **strs_ptr, size_t count)
{
	size_t	i;
	size_t	j;
	char	*str_inside;
	char	*str_outside;
	size_t	cmp_n;

	i = 0;
	while (i < count)
	{
		str_inside = *(strs_ptr + i);
		cmp_n = ft_strlen(str_inside);
		j = i + 1;
		while (j < count)
		{
			str_outside = *(strs_ptr + j);
			if (ft_strncmp(str_inside, str_outside, cmp_n
					+ (cmp_n < ft_strlen(str_outside))) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_ints_only(char **strs_ptr, size_t count)
{
	size_t	i;
	size_t	str_len;
	size_t	str_i;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = *(strs_ptr + i);
		str_len = ft_strlen(str);
		if (str_len > 9 + (str[0] == '-' || str[0] == '+'))
			return (0);
		str += (str[0] == '-' || str[0] == '+');
		str_i = 0;
		while (str[str_i])
		{
			if (str[str_i] < '0' || str[str_i] > '9')
				return (0);
			str_i++;
		}
		i++;
	}
	return (1);
}
