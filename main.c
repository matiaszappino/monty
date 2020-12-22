#include "monty.h"
stainst_t stainst;
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vectors
 * Return: exit succes on succes or exit failure on failiure
 */
int main(int argc, char *argv[])
{
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv, &head);
	exit(EXIT_SUCCESS);
}
