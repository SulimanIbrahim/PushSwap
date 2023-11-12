/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:25:49 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/13 01:13:01 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void index_bits_max(struct stack *stack)
{
    node_t *head;
    int max_number;
    int max_bits;

    head = stack->top;
    max_number = 0;
    while(head)
    {
        if(head->index > max_number)
            max_number = head;
        head = head->next;
    }

    printf("%d", max_number);
    return;
}