/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:46:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/22 05:28:20 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void none_integers_check(char **arg) 
{
    int i;
	int j;

	i = 0;
    while (arg[i]) 
	{
        j = 0;
        while (arg[i][j] != '\0') 
		{
            if ((arg[i][j] >= '0' && arg[i][j] <= '9'))
                j++;
        	else if (arg[i][j] == '-' || arg[i][j] == '+')
                {
					if (j > 0 || (arg[i][j + 1] == '\0'))
						{
							free_args(arg, 1);
							exit(1);
						}
					else
						j++;
				}
			else
				{
					free_args(arg, 1);
					exit(1);
				}
		}
        i++;
    }
}

int check_duplcates(stack *stack_a)
{
	node_t *current;
    node_t *temp;

    current = stack_a->top;

    while(current->next)
    {
    	temp = current->next;
        while(temp)
		{
			if(current->content == temp->content)
				{
					free_nodes(stack_a, 1);
					exit(1);
				}
			temp = temp->next;
		}
        current = current->next;
    }

    return (0);
}

char **parsing(int ac, char **av)
{
	int i;
	int check;
	char *joined;
	char **splitted;
	 
	i = 0;
	(void)ac;
	check = 0;
	joined = ft_strdup("");
	if(joined == NULL)
		return(free(joined), NULL);
	while(av[++i])
	{
		joined = ft_strjoin(joined, av[i]);
		joined = ft_strjoin(joined, " ");
	}
 	splitted = ft_split(joined, ' ');
	if(splitted == NULL)
		return(free(joined), NULL);
	none_integers_check(splitted);
	if (check == 1)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (free (joined), splitted);
}

// void free_nodes(stack *stack)
// {
// 	node_t *current;
// 	node_t *next_node;
	
// 	current = stack->top;
// 	next_node = NULL;
// 	while(current != NULL)
// 	{
// 		next_node = current->next;
// 		free(current);
// 		current = next_node;
// 	}
// }