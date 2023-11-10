/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 04:10:27 by suibrahi          #+#    #+#             */
/*   Updated: 2023/10/19 17:03:58 by suibrahi         ###   ########.fr       */
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

void push(struct stack *stack, int content)
{
    node_t *newNode;

    newNode = (node_t *)malloc(sizeof(node_t));
    newNode->content = content;
    newNode->next = stack->top;
    stack->top = newNode;
}
void pop(struct stack *stack)
{
    stack->top = stack->top->next; 
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
    struct node *current;

    current = stack->top;

    ft_lstlast(stack->top);
    current->next->next = stack->top;
    stack->top = current->next;
    current->next=NULL;
} 

void printStack(struct stack *stack) 
{
    struct node *current;

    current = stack->top;
    while (current != NULL) 
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}

// int main()
// { 
//         struct stack stack_A, stack_B;
//     creat_stack(&stack_A);
//     creat_stack(&stack_B);

//     push(&stack_A, 5);
//     push(&stack_A, 4);
//     push(&stack_A, 0);
//     push(&stack_A, 8);
 
//     rotate_a(&stack_A);
//     printStack(&stack_A);
//    // printf("index num = %d Position num = %d\n", peek(&stack_A,4), peek(&stack_A,4) + 1);
// }