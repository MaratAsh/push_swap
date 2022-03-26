/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:32:10 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 09:10:26 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_set_indexes(int *nums, t_dlist *start, size_t count)
{
	t_dlist	*dlist;
	size_t	i;
	t_data	*data;

	ft_sort_ints(nums, count);
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
}

static void	ft_noooooooorm(char **strs, char **ptr, int *nums, char *intstr)
{
	if (nums)
		free(nums);
	if (ptr != strs)
		ft_free((void **) ptr);
	free(intstr);
	ft_error();
}

static t_dlist	*ft_convert_norm_proccess_int(char **strs, char **ptr,
				int *nums, char *intstr)
{
	static t_dlist	*start;
	static t_dlist	*dlist;
	static size_t	i;

	if (!dlist)
		i = 0;
	else
		i++;
	ft_strint_to_norm(ptr + i);
	//while (ptr[i][0] == '0' && (ptr[i][1] >= '0' && ptr[i][1] <= '9'))
	//	ptr[i]++;
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
			ft_dlstclear(&start, free);
		ft_noooooooorm(strs, ptr, nums, intstr);
	}
	free(intstr);
	return (start);
}

static void	ft_convert_norm(char **strs, char **ptr,
				int *nums, t_dlist **start_ptr)
{
	size_t	i;
	char	*intstr;

	*start_ptr = NULL;
	i = 0;
	while (ptr[i])
	{
		nums[i] = ft_atoi(ptr[i]);
		intstr = ft_itoa(nums[i]);
		if (i == 0)
			*start_ptr = ft_convert_norm_proccess_int(strs, ptr, nums, intstr);
		else
			ft_convert_norm_proccess_int(strs, ptr, nums, intstr);
		i++;
	}
}

t_dlist	*ft_convert(char **strs, size_t count)
{
	char	**ptr;
	t_dlist	*start;
	int		*nums;

	if (count == 0)
		ft_error();
	if (count == 1 && ft_strchr(*strs, ' ') != NULL)
	{
		ptr = ft_split(*strs, ' ');
		count = ft_count((void **) ptr);
	}
	else
		ptr = strs;
	nums = malloc(sizeof(int) * count);
	if (!nums)
		ft_error();
	ft_convert_norm(strs, ptr, nums, &start);
	ft_set_indexes(nums, start, count);
	free(nums);
	if (ptr != strs)
		ft_free((void **) ptr);
	return (start);
}
