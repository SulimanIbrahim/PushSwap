/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:28:26 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
}

void	free_args(char **av, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		write(2, "Error\n", 7);
	if (av)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
}

void	free_nodes(t_stack *stack, int flag)
{
	if (flag == 1)
		write(2, "Error\n", 7);
	while (stack->top != NULL)
	{
		pop(stack);
	}
}

void	creat_stack(t_stack *stack)
{
	stack->top = NULL;
}
