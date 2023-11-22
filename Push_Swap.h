/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:32:31 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/21 23:38:27 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft-42/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct node
{
    int content;
    int index;
    struct node *next;
} node_t;

typedef struct stack
{
    struct node *top;
} stack;

node_t	*ft_lstlast(node_t  *stack);
node_t *ft_lstnew(int content);
void push_a(struct stack *stack_b, struct stack *stack_a);
void push_b(struct stack *stack_a, struct stack *stack_b);
void none_integers_check(char **arg);
void radix(stack *stack_a, stack *stack_b);
void index_bits_max(struct stack *stack);
void add_node(node_t **node, node_t *new);
void push_to_stack(struct stack *stack, int content);
void rotate_a(struct stack *stack);
void rotate_reverse_a(struct stack *stack);
void creat_stack(struct stack *stack);
void pop(struct stack *stack);
void sort_stacks(stack *a, stack *b, int ac);
void free_nodes(stack *stack, int flag);
void free_args(char **av, int flag);
int peek(struct stack *stack, int content);
int is_sorted(stack *stack_a);
int stack_lengh(node_t *node);
void printStack(struct stack *stack);
char **parsing(int ac, char **av);
void free_args(char **av, int flag);
int check_duplcates(stack *stack_a);
node_t *set_index_to_mins(stack *stack);




#endif