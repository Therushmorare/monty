#include "monty.h"

/**
 * pint - prints element at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * pop - removes element at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = (*stack);
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next != NULL)
	{
		(*stack) = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		(*stack) = NULL;
	}

	free(temp);
}


/**
 * swap - swaps the two top elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
