#include "monty.h"

/**
 * add - function to add values to stack
 * @stack: stack pointer value
 *
 * Return: nothing
 */

void add(stack_t **stack)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top_val = *stack;
	stack_t *next = top_val->next;

	next->n += top_val->n;
	pop(stack);
}
