#include "monty.h"
/**
 * functions - adds a new node at the beginning of a dlistint_t list.
 * @token: token
 * @token_two: token_two
 * @line_number: line number
 * Return: void
 */
void if_statements(stack_t **stack, char *token, char *token_two, unsigned int line_number)
{
    if ((strcmp(token, "push") == 0) && token_two != NULL)
			check_number(token_two, line_number);
	else if ((strcmp(token, "push")) == 0 && token_two == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
    }
	if (token)
		functions(token, stack, line_number);
}