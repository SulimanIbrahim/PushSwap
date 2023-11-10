 #include "Push_Swap.h"

 int main(int ac, char **av)
{
      struct stack stack_A, stack_B;
    creat_stack(&stack_A);
    creat_stack(&stack_B);

    push(&stack_A, 5);
    push(&stack_A, 4);
    push(&stack_A, 0);
    push(&stack_A, 8);
 
    rotate_a(&stack_A);
    printStack(&stack_A);
    
	// int i = 1;
	// int check = 0;
	// char *joined = ft_strdup("");
	// int numbers;
	// struct stack stack_A, stack_B;
    // creat_stack(&stack_A);
	// while(av[i])
	// {
	// 	joined = ft_strjoin(joined, av[i]);
	// 	i++;
	// }
	
 	// char **splitted = ft_split(joined, ' ');
	// check = none_integers_check(splitted);
	// if (check == 1)
	// {
	// 	printf("ERROR");
	// 	return 0;
	// }
	// while(*splitted)
	// {
	// 	numbers = ft_atoi(*splitted++);
	// 	if(numbers == 0)
	// 	{
	// 		printf("ERROR");
	// 		return 0;
	// 	}
	// 	push(&stack_A, numbers);
	// }
	// printStack(&stack_A);
}