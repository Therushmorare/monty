#include "monty.h"

/**
 * divide - function that divs values to stack
 * @stack: stack pointer
 * @line_number: number of lines in a file
 *
 * Return: nothing
 **/

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top_val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_val = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= top_val->n;
	(*stack)->prev = NULL;

	free(top_val);
}
