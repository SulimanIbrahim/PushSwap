/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:07:51 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 19:26:11 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_node	*get_min(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		got_min;

	current = stack->top;
	got_min = 0;
	temp = NULL;
	while (current)
	{
		if (current->index == -1 && (got_min == 0
				|| temp->content > current->content))
		{
			temp = current;
			got_min = 1;
		}
		current = current->next;
	}
	return (temp);
}

t_node	*set_index_to_mins(t_stack *stack)
{
	t_node	*current;
	int		index;

	index = 0;
	current = get_min(stack);
	while (current)
	{
		current->index = index++;
		current = get_min(stack);
	}
	return (current);
}

static void	to_stack(char **args, t_stack *stack)
{
	int	index;
	int	numbers;
	int	flag;

	index = 0;
	flag = 0;
	while (args[index])
		index++;
	while (index > 0)
	{
		numbers = ft_atoi(args[--index], args, &flag);
		if (flag == 1)
		{
			free_nodes(stack, JUST_FREE);
			exit(1);
		}
		push_to_stack(stack, numbers);
	}
}

int	main(int ac, char **av)
{
	char			**args;
	t_stack			stack_a;

	creat_stack(&stack_a);
	if (ac >= 2)
	{
		args = parsing(av);
		to_stack(args, &stack_a);
		free_args(args, JUST_FREE);
		check_duplcates(&stack_a);
		sort_stacks(&stack_a);
		free_nodes(&stack_a, JUST_FREE);
	}
	return (0);
}
