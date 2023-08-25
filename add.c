#include "monty.h"

/**
 * add - function that addss values to stack
 * @stack: stack pointer
 * @line_number: number of lines in a file
 *
 * Return: nothing
 **/

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top_val = *stack;
	*stack = (*stack)->next;
	(*stack)->n += top_val->n;
	(*stack)->prev = NULL;

	free(top_val);
}
