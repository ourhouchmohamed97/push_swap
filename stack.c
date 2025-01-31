#include "stack.h"
Stack *create_stack(int capacity)
{
	if (capacity <= 0)
		return NULL;
	Stack *stack = malloc(sizeof(Stack));
	if (stack == NULL)
		return NULL;
	stack->collection = malloc(sizeof(int) * capacity);
	if (stack->collection == NULL)
	{
		free(stack);
		return NULL;
	}
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

void destroy_stack(Stack *stack)
{
	free(stack->collection);
	free(stack);
}

bool is_full(Stack *stack)
{
	return stack->capacity == stack->size;
}

bool is_empty(Stack *stack)
{
	return stack->size == 0;
}

bool push(Stack *stack, int item)
{
	if (is_full(stack))
		return false;
	stack->collection[stack->size] = item;
	stack->size++;
	return true;
}

bool peek(Stack *stack, int *item)
{
	if (is_empty(stack))
		return false;
	*item = stack->collection[stack->size - 1];
	return true;
}

bool pop(Stack *stack, int *item)
{
	if (is_empty(stack))
		return false;
	stack->size--;
	*item = stack->collection[stack->size];
	return true;
}

int main(void)
{
	Stack *stack = create_stack(5);
	if (stack == NULL)
	{
		printf("error creating stack.\n");
		return 1;
	}
	if (is_empty(stack))
		printf("stack is empty\n");
	push(stack, 2);
	printf("stack size: %d\n", stack->size);
	push(stack, 9);
	push(stack, 4);
	push(stack, 7);
	push(stack, 18);
	if (is_full(stack))
		printf("stack is full.\n");
	printf("stack size: %d\n", stack->size);

	bool try_push = push(stack, 5);
	if (try_push == false)
		printf("push failed.\n");
	int peek_val = 0;
	peek(stack, &peek_val);
	printf("peek value is: %d\n", peek_val);
	int pop_val = 0;
	for (int i = 0; i < 5; i++)
	{
		pop(stack, &pop_val);
		printf("popped value is: %d\n", pop_val);
	}
	bool try_pop = pop(stack, &pop_val);
	if (try_pop == false)
		printf("pop failed.\n");
	bool try_peek = peek(stack, &peek_val);
	if (try_peek == false)
		printf("peek failed.\n");

	destroy_stack(stack);

	return 0;
}