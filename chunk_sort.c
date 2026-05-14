/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:36:46 by ksaotome          #+#    #+#             */
/*   Updated: 2026/05/14 20:54:28 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	root;

	if (nb <= 0 || nb > INT_MAX)
		return (0);
	root = 0;
	while (nb > root * root)
	{
		root++;
		if (nb = root * root)
			return (root);
	}
	return (root - 1);
}

void	index_stack(t_stack *a, int total_size)
{
	int		*arr;
	t_node	*node;
	int		i;
	int		j;

	arr = malloc(total_size);
	node = a->top;
	i = 0;
	while (node)
	{
		arr[i++] = node->value;
		node = node->next;
	}

	sort_int_array(arr, total_size);

	node = a->top;
	while (node)
	{
		i = 0;
		while (i < total_size)
		{
			if (arr[i] == node->value)
			{
				node->rank = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(arr);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_count;
	int	chunk_size;

	total_size = get_stack_size(a);
	chunk_count = ft_sqrt(total_size);
	chunk_size = (total_size + chunk_count - 1) / chunk_count;
}