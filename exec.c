#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: count line
* @file: poiner to file
* @line: line
* Return: nothing
*/
int execute(char *line, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int i = 0;
	char *op;
	instruction_t oplist[] = {
				{"push", push},
				{"pall", pall},
				{NULL, NULL}
				};
	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (oplist[i].opcode && op)
	{
		if (strcmp(op, oplist[i].opcode) == 0)
		{	oplist[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && oplist[i].opcode == NULL)
	{	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(line);
		f_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
