#include "monty.h"

global_var global = {NULL, NULL};
/*delete comment*/

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

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
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		global.line = line;
		counter++;
		if (read_line > 0)
		{
			execute(line, &stack, counter, file);
		}
		free(line);
	}
	f_stack(stack);
	fclose(file);
return (0);
}
