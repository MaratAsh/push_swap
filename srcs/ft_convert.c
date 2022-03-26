/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:32:10 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/26 11:28:55 by alcierra         ###   ########.fr       */
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

static void	ft_noooooooorm(int *nums, char *intstr)
{
	if (nums)
		free(nums);
	free(intstr);
	ft_error();
}

static t_dlist	*ft_convert_norm_proccess_int(char **strs, size_t i,
				int *nums, char *intstr)
{
	static t_dlist	*start;
	static t_dlist	*dlist;
	char			*input_str;

	input_str = strs[i];
	ft_strint_to_norm(&input_str);
	if (ft_strncmp(input_str, intstr, ft_strlen(intstr) + 1) == 0
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
		ft_noooooooorm(nums, intstr);
	}
	free(intstr);
	return (start);
}

static void	ft_convert_norm(char **strs,
				int *nums, t_dlist **start_ptr)
{
	size_t	i;
	char	*intstr;

	*start_ptr = NULL;
	i = 0;
	while (strs[i])
	{
		nums[i] = ft_atoi(strs[i]);
		intstr = ft_itoa(nums[i]);
		if (i == 0)
			*start_ptr = ft_convert_norm_proccess_int(strs, i, nums, intstr);
		else
			ft_convert_norm_proccess_int(strs, i, nums, intstr);
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
		start = ft_convert(ptr, count);
		ft_free((void **) ptr);
		return (start);
	}
	nums = malloc(sizeof(int) * count);
	if (!nums)
		ft_error();
	ft_convert_norm(strs, nums, &start);
	ft_set_indexes(nums, start, count);
	free(nums);
	return (start);
}
