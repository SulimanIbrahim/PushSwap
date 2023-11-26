/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:25:49 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:16:43 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	bits_max(t_node *node)
{
	t_node	*current;
	int		max_number;
	int		max_bits;

	current = node;
	max_bits = 0;
	max_number = 0;
	while (current)
	{
		if (current->content > max_number)
		{
			max_number = current->content;
		}
		current = current->next;
	}
	while (max_number != 0)
	{
		max_bits++;
		max_number /= 2;
	}
	return (max_bits);
}

void	radix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	stack_a_len;
	int	i;
	int	j;

	max_bits = bits_max(a->top);
	i = 0;
	while (i < max_bits)
	{
		stack_a_len = stack_lengh(a->top);
		j = 0;
		while (j < stack_a_len && is_sorted(a) == 0)
		{
			if ((a->top->index / (1 << i)) % 2 == 1)
				rotate_a(a);
			else if ((a->top->index / (1 << i)) % 2 == 0)
				push_b(a, b);
			j++;
		}
		while (b->top)
			push_a(b, a);
		i++;
	}
}

void	sort_stacks(t_stack *a)
{
	t_stack	b;

	creat_stack(&b);
	set_index_to_mins(a);
	if (is_sorted(a) == 0)
	{
		if (stack_lengh(a->top) == 3)
			sort_three(a);
		else if (stack_lengh(a->top) == 4)
			sort_four(a, &b); 
		else if (stack_lengh(a->top) == 5)
			sort_five(a, &b); 
		else 
			radix(a, &b);
	}
	free_nodes(&b, 0);
}
