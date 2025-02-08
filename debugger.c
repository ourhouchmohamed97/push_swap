#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	ft_index(t_stack *stack)
{
    int i, j;
    int min_value;
    int min_index;

    if (!stack || !stack->tab || stack->len == 0)
        return;
	i = 0;
    while (i < stack->len)
    {
        stack->index[i] = -1;
		i++;
    }
	i = 0;
    while (i < stack->len)
    {
        min_value = INT_MAX;
        min_index = -1;
		j = 0;
        while (j < stack->len)
        {
            if (stack->index[j] == -1 && stack->tab[j] < min_value)
            {
                min_value = stack->tab[j];
                min_index = j;
            }
			j++;
        }
        stack->index[min_index] = i;
		i++;
    }
}

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while(i < stack_a->len)
	{
		if(stack_a->tab[i - 1] > stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_compare(t_stack *stack_a, t_stack *stack_b, char c)
{
	if (c == 'a' && stack_a->len > 1
		&& stack_a->index[0] > stack_a->index[stack_a->len - 1])
		return (1);
	if (c == 'b')
	{
		if (ft_compare(stack_a, NULL, 'a'))
			rra(stack_a);
		pb(stack_a, stack_b);
		if (stack_b->len > 1 && stack_b->index[0] < stack_b->index[1])
			sb(stack_b);
	}
	return (0);
}


void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_rang;
	int	max_rang;

	min_rang = 0;
	max_rang = stack_a->len * 0.048 + 10;
	while (stack_a && !check_sort(stack_a))
		if (stack_a->index[stack_a->len - 1] < max_rang && ft_compare(stack_a, NULL, 'a'))
			rra(stack_a);
	else if (stack_a->index[0] > max_rang)
		ra(stack_a);
	else if (stack_a->index[0] < min_rang)
	{
		pb(stack_a, stack_b);
		if (stack_a->index[0] > max_rang)
			rr(stack_a, stack_b);
		else
			rb(stack_b);
		min_rang = ((max_rang++), min_rang + 1);
	}
	else
	{
		ft_compare(stack_a, stack_b, 'b');
		max_rang++;
		min_rang++;
	}
}


int main()
{
    // Initialize stack_a
    t_stack stack_a;
    stack_a.len = 10;  // Testing with 10 numbers
    
    // Initialize stack_b
    t_stack stack_b;
    stack_b.len = 0;
    
    // Allocate memory for both stacks
    stack_a.tab = malloc(sizeof(int) * stack_a.len);
    stack_a.index = malloc(sizeof(int) * stack_a.len);
    stack_b.tab = malloc(sizeof(int) * stack_a.len);  // Same size as stack_a
    stack_b.index = malloc(sizeof(int) * stack_a.len);
    
    if (!stack_a.tab || !stack_a.index || !stack_b.tab || !stack_b.index)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    // Fill stack_a with unsorted numbers
    stack_a.tab[0] = 45;
    stack_a.tab[1] = 22;
    stack_a.tab[2] = 65;
    stack_a.tab[3] = 12;
    stack_a.tab[4] = 89;
    stack_a.tab[5] = 34;
    stack_a.tab[6] = 91;
    stack_a.tab[7] = 17;
    stack_a.tab[8] = 28;
    stack_a.tab[9] = 53;

    // Print original array
    printf("Original array:\n");
    for (int i = 0; i < stack_a.len; i++)
        printf("%d ", stack_a.tab[i]);
    printf("\n\n");

    // Index the stack
    ft_index(&stack_a);

    // Print indexed array
    printf("After indexing:\n");
    printf("Value\tIndex\n");
    for (int i = 0; i < stack_a.len; i++)
        printf("%d\t%d\n", stack_a.tab[i], stack_a.index[i]);
    printf("\n");

    // Check if initially sorted
    printf("Initially sorted? %s\n\n", check_sort(&stack_a) ? "Yes" : "No");

    // Sort the stack
    //ft_sort(&stack_a, &stack_b);

    // Print final results
    printf("After sorting:\n");
    printf("Stack A (len=%d):\n", stack_a.len);
    for (int i = 0; i < stack_a.len; i++)
        printf("%d ", stack_a.tab[i]);
    printf("\n\n");

    printf("Stack B (len=%d):\n", stack_b.len);
    for (int i = 0; i < stack_b.len; i++)
        printf("%d ", stack_b.tab[i]);
    printf("\n\n");

    // Verify if sorted
    printf("Finally sorted? %s\n", check_sort(&stack_a) ? "Yes" : "No");

    // Free allocated memory
    free(stack_a.tab);
    free(stack_a.index);
    free(stack_b.tab);
    free(stack_b.index);

    return (0);
}



// // Function to print the values and their assigned indices
// void print_stack(t_stack *stack)
// {
//     for (int i = 0; i < stack->len; i++)
//     {
//         printf("Value: %d, Index: %d\n", stack->tab[i], stack->index[i]);
//     }
// }

// int main()
// {
//     int values[] = {50, 20, 40, 10, 30};
//     t_stack stack;
//     stack.len = sizeof(values) / sizeof(values[0]);

//     // Allocate memory for tab and index arrays
//     stack.tab = malloc(stack.len * sizeof(int));
//     stack.index = malloc(stack.len * sizeof(int));

//     if (!stack.tab || !stack.index)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     // Copy values into the stack's tab array
//     for (int i = 0; i < stack.len; i++)
//     {
//         stack.tab[i] = values[i];
//     }
//     ft_index(&stack);

//     // Print the stack values with their assigned indices
//     printf("\nAfter assigning indices:\n");
//     print_stack(&stack);

//     // Free allocated memory
//     free(stack.tab);
//     free(stack.index);

//     return 0;
// }