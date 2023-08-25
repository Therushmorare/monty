#include "monty.h"

#define MAX_LINE_LENGTH 256

global_var global = {NULL, NULL, NULL};

/**
 * main - function that handles monty
 * @argc: arg
 * @argv: argv
 * Return: zero
 */

int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	global.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	counter = 0;

	while (fgets(line, sizeof(line), file))
	{
		size_t len = strlen(line);

		counter++;

		global.line = line;

		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';

		execute(line, &stack, counter, file);
	}

	f_stack(stack);
	fclose(file);

	return (0);
}
