#include "monty.h"

/**
 * mod - function that mods values to stack
 * @stack: stack pointer
 * @line_number: number of lines in a file
 *
 * Return: nothing
 **/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top_val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_val = *stack;
	*stack = (*stack)->next;
	if (top_val->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= top_val->n;
	(*stack)->prev = NULL;

	free(top_val);
}
