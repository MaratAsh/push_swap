/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:52:20 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/21 19:00:58 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_all	*ft_create_stacks(char **strs, size_t count)
{
	t_all	*data;

	data = malloc(sizeof(t_all));
	if (!data)
		return (data);
	data->st_a = ft_convert(strs, count);
	data->st_b = NULL;
	return (data);
}
