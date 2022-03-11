/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:32:10 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 20:35:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_dlist	*ft_create_dlist(void *data, t_dlist *prev, t_dlist *next)
{
	t_dlist	*elem;

	elem = malloc(sizeof(t_dlist));
	if (!elem)
		return (NULL);
	elem->content = data;
	elem->next = next;
	elem->prev = prev;
	if (prev)
		prev->next = elem;
	if (next)
		next->prev = elem;
	return (elem);
}

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

t_dlist	*ft_convert(char **strs, size_t count)
{
	char	**ptr;
	char	*intstr;
	size_t	i;
	t_dlist	*dlist;
	t_dlist	*start;
	t_data	*data;
	int		*nums;

	dlist = NULL;
	if (count == 1 && ft_strchr(*strs, ' ') != NULL)
	{
		ptr = ft_split(*strs, ' ');
		count = ft_count((void **) ptr);
	}
	else
		ptr = strs;
	i = 0;
	nums = malloc(sizeof(int) * count);
	if (!nums)
		ft_error();
	start = NULL;
	while (ptr[i])
	{
		nums[i] = ft_atoi(ptr[i]);
		intstr = ft_itoa(nums[i]);
		if (intstr)
		{
			while (ptr[i][0] == '0' && (ptr[i][1] >= '0' && ptr[i][1] <= '9'))
				ptr[i]++;
			if (ft_strncmp(ptr[i], intstr, ft_strlen(intstr) + 1) == 0
				&& ft_check_coincedence(nums, i, nums[i]) == 0)
			{
				dlist = ft_create_dlist(ft_create_data(nums[i], 0), dlist, NULL);
				if (i == 0)
					start = dlist;
			}
			else
			{
				if (start)
					ft_dlstclear(&start, NULL);
				if (nums)
					free(nums);
				if (ptr != strs)
					ft_free((void **) ptr);
				free(intstr);
				ft_error();
			}
			free(intstr);
		}
		i++;
	}

	printf("i = %lu\ncount = %lu\n", i, count);
	i = 0;
	while (i < count)
	{
		printf("%d ", nums[i]);
		i++;
	}
	printf("\n");
	write(1, "some\n", 5);
	ft_sort_ints(nums, 3);
	write(1, "some 2\n", 7);
	i = 0;
	while (i < count)
	{
		printf("%d ", nums[i]);
		i++;
	}
	printf("\n");
	dlist = start;
	while (dlist)
	{
		data = ft_dlstdata(dlist);
		i = 0;
		while (i < count)
		{
			if (data->number == nums[i])
			{
				data->index = i;
				break ;
			}
			i++;
		}
		dlist = dlist->next;
	}
	if (ptr != strs)
		ft_free((void **) ptr);
	return (start);
}
