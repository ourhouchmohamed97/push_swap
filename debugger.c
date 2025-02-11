#include "include/push_swap.h"
#include <limits.h>
#include <stdio.h>

void	ft_index(t_stack *stack)
{
	int(min_value), (min_index), (i), (j);
	if (!stack || !stack->tab || stack->len == 0)
		return ;
	stack->index = malloc(sizeof(int) * stack->len);
	if (!stack->index)
		return ;
	i = 0;
	while (i < stack->len)
		stack->index[i++] = -1;
	i = 0;
	while (i < stack->len)
	{
		(min_value = INT_MAX, min_index = -1, j = 0);
		while (j < stack->len)
		{
			if (stack->index[j] == -1 && stack->tab[j] < min_value)
			{
				min_value = stack->tab[j];
				min_index = j;
			}
			j++;
		}
		stack->index[min_index] = i++;
	}
}

// Function to print the values and their assigned indices
void	print_stack(t_stack *stack)
{
	for (int i = 0; i < stack->len; i++)
	{
		printf("Value: %d, Index: %d\n", stack->tab[i], stack->index[i]);
	}
}

int	main(void)
{
	int values[] = {50, 20, 40, 10, 30};
	t_stack stack;
	stack.len = sizeof(values) / sizeof(values[0]);

	// Allocate memory for tab and index arrays
	stack.tab = malloc(stack.len * sizeof(int));
	stack.index = malloc(stack.len * sizeof(int));

	if (!stack.tab || !stack.index)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	// Copy values into the stack's tab array
	for (int i = 0; i < stack.len; i++)
	{
		stack.tab[i] = values[i];
	}
	ft_index(&stack);

	// Print the stack values with their assigned indices
	printf("\nAfter assigning indices:\n");
	print_stack(&stack);

	// Free allocated memory
	free(stack.tab);
	free(stack.index);

	return (0);
}