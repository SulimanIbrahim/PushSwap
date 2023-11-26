/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 04:10:27 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:27:36 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	swap_a(t_stack *stack)
{
	struct node	*first_node;
	struct node	*second_node;
	struct node	*temp;

	first_node = stack->top;
	second_node = stack->top->next;
	temp = second_node->next;
	second_node->next = first_node;
	first_node->next = temp;
	stack->top = second_node;
	write(1, "sa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*new_node;
	t_node	*old_node;

	new_node = stack_b->top;
	old_node = stack_a->top;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_nodes(stack_a, 0);
		free_nodes(stack_b, 0);
	}
	new_node->content = old_node->content;
	new_node->next = stack_b->top;
	stack_b->top = new_node;
	new_node->index = old_node->index;
	pop(stack_a);
	write(1, "pb\n", 3);
}

void	push_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*new_node;
	t_node	*old_node;

	new_node = stack_a->top;
	old_node = stack_b->top;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_nodes(stack_a, 0);
		free_nodes(stack_b, 0);
	}
	new_node->content = old_node->content;
	new_node->next = stack_a->top;
	stack_a->top = new_node;
	new_node->index = old_node->index;
	pop(stack_b);
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack->top;
	tail = ft_lstlast(head);
	stack->top = head->next;
	head->next = NULL;
	tail->next = head;
	write(1, "ra\n", 3);
}

void	rotate_reverse_a(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;
	t_node	*temp;

	head = stack->top;
	temp = stack->top;
	while (head->next->next)
		head = head->next;
	tail = ft_lstlast(temp);
	stack->top = tail;
	tail->next = temp;
	head->next = NULL;
	write(1, "rra\n", 4);
}

// void printStack(t_stack *stack)
// {
// 	struct node *current;

// 	current = stack->top;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", current->content);
// 		current = current->next;
// 	}
// }
