/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 21:19:42 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	push_to_stack(t_stack *stack, int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		free_nodes(stack, 0);
	new_node->content = content;
	new_node->next = stack->top;
	stack->top = new_node;
	new_node->index = -1;
}

t_node	*ft_lstlast(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_lengh(t_node *node)
{
	int		len;
	t_node	*current;

	len = 0;
	current = node;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
