#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void f_stack(stack_t *head)
{
	stack_t *stack;

	stack = head;
	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}
