#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct
{
	int *collection; // pointer to dynamicly allocated array of integers
	int capacity; // the size of dynamicly allocated array of integers
	int size; // nomber of element stored in dynamicly allocated array of integers
} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);
