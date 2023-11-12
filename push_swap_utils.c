/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/10 16:52:57 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

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