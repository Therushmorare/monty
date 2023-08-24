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
	char *token;
	int number;

	token = strtok(global.line, " \t\n");
	token = strtok(NULL, " \t\n");

	if (isdigit(token))
	{
		number = atoi(token);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);

	}

	new_elem = (stack_t *)malloc(sizeof(stack_t));
	if (new_elem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_elem->prev = NULL;
	new_elem->n = number;
	new_elem->next = (*stack);

	if (*stack)
	{
		(*stack)->prev = new_elem;
	}

	*stack = new_elem;	
}
