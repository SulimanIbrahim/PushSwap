/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/22 05:26:17 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"


void free_args(char **av, int flag)
{
    int i;

    i = 0;
    if (flag == 1)
        write(2, "Error\n", 7);
    if (av)
    {
        while(av[i])
        {
            free(av[i]);
            i++;   
        }
        free(av);
    }
}
void free_nodes(stack *stack, int flag)
{
    node_t *next_node;    
    node_t *temp;    

    next_node = NULL;
    temp = NULL;
    if (flag == 1)
        write(2, "Error\n", 7);	
    while(stack->top != NULL)
    {
        pop(stack);
        stack->top = stack->top->next;
    }
}
node_t *ft_lstnew(int content)
{
    node_t *new;

    new = (node_t *)malloc(sizeof(node_t));
    
    new->content = content;
    new->next = NULL;
    
    return(new);
}

void add_node(node_t **node, node_t *new)
{
    new->next = *node;
    *node = new;
}
int is_sorted(stack *stack_a)
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



// int main()
// {
//     int new = 345;
//     int n = 9;
//     node_t *list = ft_lstnew(&new);
//     node_t *list1 = ft_lstnew(&n);

//   // add_node(&list, list1);
//    while(list != NULL)
//    {
//     printf("%d", (int)list->content);
//     list = list->next;
//    }
//     return 0;
// }

// int main()
// {

//     int box[] = {6, 3, 5, 9, 2, 1, 7, 4, 8};
//     int i = 0;
//     int item = 9;
//     int posetion = 6;
//     int lengh = 9;
//     int n = 9;

//     while (box[i] <= lengh)
//     {
//         printf("%d", box[i]);
//         i++;
//     }
//     printf("\n");

//     i = 0;
//     n = n + 1;
//     while (posetion >= n)
//     while (box[i] <= lengh)
//     {
//         printf("%d",box[i]);
//         i++;
//     }
//             printf("\n");

//     i = 0;
//     n = n + 1;
//     while(posetion >= n)
//     {
//         box[n + 1] = box[n];
//         n--;
//     }
//     box[posetion] = item;
//     while (i < n)
//     {
//         printf("%d", box[i]);
//         i++;
//     }

//     return 0;
// }