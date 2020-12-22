#include "monty.h"
/**
 * process_file - function that opens and process the file
 * @stack: stack
 * @fp: file
 * Return: void
 */
void process_file(stack_t **stack, FILE *fp)
{
	size_t size = 0;
	ssize_t n;
	unsigned int line_number = 0;
	char *token = NULL;
	char *token_two = NULL;
	char *buffer = NULL;
	int free_count = 0;

	while ((n = getline(&buffer, &size, fp)) != EOF)
	{
		while (buffer[0] == 32)
		{
			free_count++;
			buffer++;
		}
		if (buffer[0] == '\n' || buffer[0] == '\0')
			continue;
		token = strtok(buffer, DEL);
		token_two = strtok(NULL, DEL);
		line_number++;
		if ((strcmp(token, "push") == 0) && token_two != NULL)
			check_number(token_two, line_number);
		if (token)
			functions(token, stack, line_number);
		/**if (strlen(token) != 0 && token[0] != '#')
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}**/
		/**functions(token, stack, line_number);**/
	}
	while (free_count > 0)
	{
		buffer--;
		free_count--;
	}
	free(buffer);
}