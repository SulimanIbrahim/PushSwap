/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:25:49 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/19 00:48:02 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int is_sorted(stack *stack_a)
{
    node_t *current;
    node_t *temp;

    current = stack_a->top;
    temp = stack_a->top;

    while(current->next)
    {
        if(current->index > current->next->index)
            return (0);
        current = current->next;
    }

    return (1);
}
static int bits_max(node_t *node)
{
    node_t *current;
    int max_number;
    int max_bits;

    current = node;
    max_bits = 0;
    max_number = 0;
    while(current)
    {
        if(current->content > max_number)
        {
            max_number = current->content;
        }
        current = current->next;
    }
    while(max_number != 0)
    {
            max_bits++;
            max_number /= 2;
    }
    return (max_bits);
}

int stack_lengh(node_t *node)
{
    int len;
    node_t *current;
    
    len = 0;
    current = node;
    while (current)
    {
        current = current->next;
        len++;
    }
    return(len);
}

void radix(stack *a, stack *b)
{
    int max_bits = bits_max(a->top);


    int i = 0;
    while (i < max_bits)
    {
        int stack_a_len = stack_lengh(a->top);
        int j = 0;
        while (j < stack_a_len && is_sorted(a) == 0)
        {
          //  int mask = 1 << i;
            if ((a->top->index / (1 << i)) % 2 == 1)
            {
                rotate_a(a);
            }
            else if ((a->top->index / (1 << i)) % 2 == 0)
            {
                push_b(a, b);
            }
            j++;
        }
        while (b->top)
        {
            push_a(b, a);
        }
        i++;
    }
    
}
// void radix(stack *stack_a, stack *stack_b)
// {
//     node_t *current_a;
//     node_t *current_b;
//     int max_bits;
//     int len;
//     int i;
//     int j;

//     current_a = stack_a->top;
//     current_b = stack_b->top;
//     i = 0;
//     max_bits = bits_max(current_a);
//     printf(" max bits: %d\n", max_bits);
//     len = stack_lengh(current_a);
//     while(i < max_bits)
//     {
//         j = 0;
//         printf("Hello1\n");
//         while (j < len)
//         {
//             j++;
//             stack_a->top = current_a;
//             printf("Hello2\n");
//             if((current_a->index / (1 << i)) % 2 == 1)
//             {
//                 rotate_a(stack_a);
//                 printf("finish rotate_ a\n");
//             }
//             else 
//             {
//                 push_b(stack_a, stack_b);
//                 printf("finish push from a to b\n");
//             }
//         }
//          printf("finish first loop\n");
//         while(stack_lengh(current_b))
//         {
//             printf("Hello1111111\n");
//             push_a(stack_b, stack_a);
//         }
//          printf("finish second loop\n");

//         i++;
//     }
// }