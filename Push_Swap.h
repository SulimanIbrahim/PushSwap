#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "libft/Libft-42/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

typedef struct node
{
    int content;
    struct node *next;
} node_t;


typedef struct stack
{
    struct node *top;
} stack;

node_t	*ft_lstlast(node_t  *stack);
node_t *ft_lstnew(int content);

void add_node(node_t **node, node_t *new);
void push(struct stack *stack, int content);
void rotate_a(struct stack *stack);
void creat_stack(struct stack *stack);
void pop(struct stack *stack);
int peek(struct stack *stack, int content);
void printStack(struct stack *stack);





#endif