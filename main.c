/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:07:51 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/22 05:33:27 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static node_t *get_min(struct stack *stack)
{
	node_t *current = stack->top;
	node_t *temp;
	 int got_min;

	got_min = 0;
	temp = NULL;
	while(current)
	{
		if(current->index == -1 && (got_min == 0 || temp->content > current->content))
			{
				temp = current;
				got_min = 1;
			}
		current = current->next;
	}
	return(temp);
}

node_t *set_index_to_mins(stack *stack)
{
	node_t	*current;
	int		index;

	index = 0;
	current = get_min(stack);
	while(current)
	{
		current->index = index++;
		current = get_min(stack);
	}
	return(current);
}
 int main(int ac, char **av)
{
	char **args;
	int numbers;
	int index;
	struct stack stack_a, stack_b;

	index = 0;
	creat_stack(&stack_a);
	creat_stack(&stack_b);
	if(ac > 2)
	{
		args = parsing(ac, av);
		while(args[index])
			index++;
		while (index > 0)
		{
			numbers = ft_atoi(args[--index]);
			push_to_stack(&stack_a, numbers);
		}
			free_args(args, 0);
			check_duplcates(&stack_a);
			sort_stacks(&stack_a, &stack_b, ac);
			//printStack(&stack_a);
	}
	return (0);
}
// node_t *set_index_to_mins(stack *stack)
// {
// 	node_t	*current;
// 	int		index;

// 	index = 0;
// 	current = get_min(stack);
// 	while(current)
// 	{
// 		current->index = index++;
// 		current = get_min(stack);
// 	}
// 	return(current);
// }
//  int main(int ac, char **av)
// {
// 	int i = 1;
// 	int check = 0;
// 	char *joined = ft_strdup("");
// 	int numbers;
// 	struct stack stack_A, stack_B;
//     creat_stack(&stack_A);
// 	check = parsing(ac, **av);
// 	while(av[i])
// 	{
// 		joined = ft_strjoin(joined, av[i]);
// 		joined = ft_strjoin(joined," ");
// 		i++;
// 	}
//  	char **splitted = ft_split(joined, ' ');
// 	check = none_integers_check(splitted);
// 	if (check == 1)
// 	{
// 		printf("ERROR");
// 		return 0;
// 	}
// 	int index = 0;
// 	while (splitted[index])
// 		index++;
// 	while(index > 0)
// 	{
// 		numbers = ft_atoi(splitted[--index]);
	
// 		push_to_stack(&stack_A, numbers);
// 	}
// 		set_index_to_mins(&stack_A);
// 		// if (ac == 3)
// 		// 	sort_three(&stack_A);
// 		// else if (ac <= 5)
// 		// 	sort_4_5()
// 		radix(&stack_A, &stack_B);
// 	//printStack(&stack_A);
// }
