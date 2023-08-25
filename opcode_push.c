#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @value: Value to push.
 */
void push(stack_t **stack, unsigned int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
