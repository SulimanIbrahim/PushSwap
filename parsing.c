/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:46:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/26 21:18:17 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	none_integers_check(char **arg)
{
	int	i;
	int	j;

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
					s7lb(arg, PRINT_ERROR);
				else
					j++;
			}
			else
				s7lb(arg, PRINT_ERROR);
		}
		i++;
	}
}

void	s7lb(char **arg, int i)
{
	if (i == JUST_EXIT)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	free_args(arg, i);
	exit(1);
}

void	check_duplcates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*temp;

	current = stack_a->top;
	if (!stack_a)
		return ;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (current->content == temp->content)
			{
				free_nodes(stack_a, PRINT_ERROR);
				exit(1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		if (*av[i] == '\0')
			s7lb(av, JUST_EXIT);
		else
		{
			if (*av)
			{
				j = 0;
				while (av[i][j] == ' ')
				{
					j++;
					if (av[i][j] == '\0')
						s7lb(av, JUST_EXIT);
				}
			}
		}
		i++;
	}
}

char	**parsing(char **av)
{
	int		i;
	char	*joined;
	char	**splitted;

	i = 0;
	check_args(av);
	joined = ft_strdup("");
	if (joined == NULL)
		return (free(joined), NULL);
	while (av[++i])
	{
		joined = ft_strjoin(joined, av[i]);
		joined = ft_strjoin(joined, " ");
	}
	splitted = ft_split(joined, ' ');
	if (splitted == NULL)
		return (free(joined), NULL);
	free(joined);
	none_integers_check(splitted);
	return (splitted);
}
