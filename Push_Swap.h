/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:32:31 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:15:46 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PRINT_ERROR 1
# define JUST_FREE 0 
# define JUST_EXIT 2 

# include "Libft-42/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct node
{
	int			content;
	int			index;
	struct node	*next;
}	t_node;

typedef struct t_stack
{
	struct node	*top;
}	t_stack;

t_node	*ft_lstlast(t_node *stack);
t_node	*set_index_to_mins(t_stack *stack);
t_node	*get_min(t_stack *stack);

char	**parsing(char **av);

void	check_args(char **av);
void	check_duplcates(t_stack *stack_a);
void	creat_stack(t_stack *stack);
void	none_integers_check(char **arg);

void	push_to_stack(t_stack *stack, int content);
void	push_a(t_stack *stack_b, t_stack *stack_a);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_reverse_a(t_stack *stack);

void	sort_stacks(t_stack *a);
void	radix(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	index_bits_max(t_stack *stack);

void	free_args(char **av, int flag);
void	free_nodes(t_stack *stack, int flag);
void	s7lb(char **arg, int i);
void	pop(t_stack *stack);

int		stack_lengh(t_node *node);
int		is_sorted(t_stack *stack_a);

#endif