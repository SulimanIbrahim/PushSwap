/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:46:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/01 22:45:14 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"


int none_integers_check(char **arg) {
    int i;
	int j;

	i = 1;
    while (arg[i]) 
	{
        j = 0;
        while (arg[i][j] != '\0') {
            if ((arg[i][j] >= '0' && arg[i][j] <= '9') 
			|| arg[i][j] == '-' || arg[i][j] == ' ' || arg[i][j] == '+') 
                j++;
        	 else 
                return 1;
        }
        i++;
    }

    return 0;
}


int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	unsigned long long	max;

	res = 0;
	sign = 1;
	max = 2147483647;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res >= max)
			return (0);
		str++;
	}
	return (res * sign); 
}

void check_doubles_array(char *arg)
{
	int i;
	int j;

	i = 1;
	while(arg[i])
	{
		j = i + 1;
		while(arg[j])
		{
			if(arg[i] == arg[j])
			{
				printf("ERROR");
				return;
			}
			j++;
		}
		i++;	
	}
}
//  int main(int ac, char **av)
// {
// 	int i = 1;
// 	int check = 0;
// 	char *joined = ft_strdup("");
// 	int numbers;
// 	struct stack stack_A, stack_B;
//     creat_stack(&stack_A);
// 	while(av[i])
// 	{
// 		joined = ft_strjoin(joined, av[i]);
// 		i++;
// 	}
	
//  	char **splitted = ft_split(joined, ' ');
// 	check = none_integers_check(splitted);
// 	if (check == 1)
// 	{
// 		printf("ERROR");
// 		return 0;
// 	}
// 	while(*splitted)
// 	{
// 		numbers = ft_atoi(*splitted++);
// 		if(numbers == 0)
// 		{
// 			printf("ERROR");
// 			return 0;
// 		}
// 		push(&stack_A, numbers);
// 	}
// 	printStack(&stack_A);
// }