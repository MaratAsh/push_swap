/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_data_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:08:20 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/23 17:19:05 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_data	*ft_create_data_element(int number, int index)
{
	t_data	*elem;

	elem = (t_data *) malloc(sizeof(elem));
	elem->number = number;
	elem->index = index;
	elem->group = 1;
	return (elem);
}
