#include "monty.h"

/**
 * pall - Prints all elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number : args for line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
