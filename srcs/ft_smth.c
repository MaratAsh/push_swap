/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:37:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 16:39:28 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

size_t	ft_count(void **ptr)
{
	char	**ptrs;
	size_t	i;

	ptrs = (char **) ptr;
	i = 0;
	while (ptrs[i])
		i++;
	return (i);
}

void	ft_free(void **ptr)
{
	char	**ptrs;
	size_t	i;

	ptrs = (char **) ptr;
	i = 0;
	while (ptrs[i])
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}
