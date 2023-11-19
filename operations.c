/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 04:10:27 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/18 21:25:54 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

node_t	*ft_lstlast(node_t  *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void creat_stack(struct stack *stack)
{
    stack->top = NULL;
}

void push_to_stack(struct stack *stack, int content)
{
    node_t *new_node;

    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->content = content;
    new_node->next = stack->top;
    stack->top = new_node;
    new_node->index = -1;
}
// void push_a(struct stack *stack, int content)
// {
//     node_t *new_node;

//     new_node = (node_t *)malloc(sizeof(node_t));
//     stack->top =  
// }
void push_b(struct stack *stack_a, struct stack *stack_b)
{
    node_t *new_node;
    node_t *old_node;

    new_node = stack_b->top;
    old_node = stack_a->top;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->content = old_node->content;
    new_node->next = stack_b->top;
    stack_b->top = new_node;
    new_node->index = old_node->index;
    pop(stack_a);
            write(1,"pb\n",3);
}
void push_a(struct stack *stack_b, struct stack *stack_a)
{
    node_t *new_node;
    node_t *old_node;

    new_node = stack_a->top;
    old_node = stack_b->top;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->content = old_node->content;
    new_node->next = stack_a->top;
    stack_a->top = new_node;
    new_node->index = old_node->index;
    pop(stack_b);
        write(1,"pa\n",3);
}

void pop(struct stack *stack)
{
    // node_t *temp;
    // temp = stack->top;
    stack->top = stack->top->next;
    // free(temp);
}

int peek(struct stack *stack, int content) 
{
    struct node *current = stack->top;
    int count = 0;

    while (current != NULL) 
    {
        if (current->content == content) 
            return count;

        current = current->next;
        count++;
    }
    return -1;
}

void rotate_a(struct stack *stack)
{
	struct node *head;
    struct node *tail;
    
    head = stack->top;
    tail = ft_lstlast(head);
    stack->top = head->next;
    head->next = NULL;
    tail->next = head;
    write(1,"ra\n",3);
}
void rotate_reverse_a(struct stack *stack)
{
    // printf("ds");
	struct node *head;
    struct node *tail;
    struct node *temp;
    
    head = stack->top;
    temp = stack->top;
    while (head->next->next)
        head = head->next;       
    tail = ft_lstlast(temp);
    stack->top = tail;
    tail->next = temp;
    head->next = NULL; 
}

void printStack(struct stack *stack) 
{
    struct node *current;

    current = stack->top;
    while (current != NULL) 
    {
        printf("%d\n", current->content);
        current = current->next;
    }
}

// int main()
// { 
//         struct stack stack_A, stack_B;
//     creat_stack(&stack_A);
//     creat_stack(&stack_B);

//     push_to_stack(&stack_A, 5);
//     push_to_stack(&stack_A, 4);
//     push_to_stack(&stack_A, 0);
//     push_to_stack(&stack_A, 8);
    
//     push_b(&stack_A, &stack_B);
//     push_b(&stack_A, &stack_B);
//     push_b(&stack_A, &stack_B);
//     push_b(&stack_A, &stack_B);
//     push_a(&stack_B, &stack_A);
//    // rotate_a(&stack_A);
//     printStack(&stack_A);
//     printf("\n");
//     printStack(&stack_B);
//    // printf("index num = %d Position num = %d\n", peek(&stack_A,4), peek(&stack_A,4) + 1);
// }