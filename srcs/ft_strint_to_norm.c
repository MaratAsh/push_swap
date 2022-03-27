/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint_to_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:51:07 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/27 11:44:32 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_strint_to_norm(char **str_ptr)
{
	char	*strint;
	char	positiv;

	strint = *str_ptr;
	while (*strint == ' ')
		strint++;
	if (*strint == '-')
	{
		positiv = 0;
		strint++;
	}
	else if (*strint == '+')
	{
		positiv = 1;
		strint++;
	}
	else
		positiv = 1;
	while (strint[0] == '0' && (strint[1] >= '0' && strint[1] <= '9'))
		strint++;
	if (positiv == 0 && *strint != '0')
		*(--strint) = '-';
	*str_ptr = strint;
}
