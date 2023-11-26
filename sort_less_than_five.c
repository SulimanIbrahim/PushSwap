/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:02:53 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:24:55 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static t_node	*get_min_one_time(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		got_min;

	current = stack->top;
	got_min = 0;
	temp = NULL;
	while (current)
	{
		if (got_min == 0 || temp->content > current->content)
		{
			temp = current;
			got_min = 1;
		}
		current = current->next;
	}
	return (temp);
}

void	sort_three(t_stack *a)
{
	if (is_sorted(a) == 0)
	{
		if (a->top->index < a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
		{
			rotate_reverse_a(a);
			swap_a(a);
		}
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index < a->top->next->next->index)
			swap_a(a);
		else if (a->top->index < a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
			rotate_reverse_a(a);
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index < a->top->next->next->index)
			rotate_a(a);
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
		{
			swap_a(a);
			rotate_reverse_a(a);
		}
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (a->top == get_min_one_time(a))
		push_b(a, b);
	else if (a->top->next == get_min_one_time(a))
	{
		swap_a(a);
		push_b(a, b);
	}
	else if (a->top->next->next == get_min_one_time(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
		push_b(a, b);
	}
	else if (a->top->next->next->next == get_min_one_time(a))
	{
		rotate_reverse_a(a);
		push_b(a, b); 
	}
	sort_three(a);
	push_a(b, a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->top == get_min_one_time(a))
		push_b(a, b);
	else if (a->top->next == get_min_one_time(a))
		swap_a(a);
	else if (a->top->next->next == get_min_one_time(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
		rotate_reverse_a(a);
	}
	else if (a->top->next->next->next == get_min_one_time(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
	}
	else if (a->top->next->next->next->next == get_min_one_time(a))
		rotate_reverse_a(a);
	push_b(a, b);
	sort_four(a, b);
	push_a(b, a);
}
