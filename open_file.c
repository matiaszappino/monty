#include "monty.h"
/**
 * open_file - function that opens and process the file
 * @argv: argument vectors
 * @stack: stack
 * Return: void
 */
int open_file(char *argv[], stack_t **stack)
{
	FILE *fp;
	char *buffer = NULL;

	if (!argv[1])
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file(stack, fp);
	free_memory(stack);
	free(buffer);
	fclose(fp);
	return (EXIT_SUCCESS);
}
