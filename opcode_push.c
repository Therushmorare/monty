#include "monty.h"

/**
 * push - adds element at top of stack
 * @stack: pointer to stack
 * @line_number: number of lines
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_elem;

	new_elem = (stack_t *)malloc(sizeof(stack_t));
	if (new_elem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_elem->prev = NULL;
	new_elem->n = ;
	new_elem->next = (*stack);


	
}
