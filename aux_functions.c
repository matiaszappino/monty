#include "monty.h"
stainst_t stainst;
/**
 * check_number - checks that token is a valid number
 * @token_two: token containing the number
 * @line_number: line number for errors
 * Return: void
 */
void check_number(char *token_two, unsigned int line_number)
{
	unsigned int i;
	int flag;
	int number;

	/**printf("Token_two en check %s:\n", token_two);**/

	if (token_two != NULL)
	{
		for (i = 0; token_two[i] != '\0'; i++)
		{
			if ((token_two[i] >= 48 && token_two[i] <= 57) || token_two[i] == 45)
			{
				flag = 1;
			}
			else
			{
				flag = 2;
				break;
			}
		}
		if (flag == 1)
		{
			number = atoi(token_two);
			stainst.number = number;
			return;
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_memory - free memory of the nodes
 * @stack: stack of nodes
 * Return: void
 */
void free_memory(stack_t **stack)
{
	stack_t *aux = NULL;
	stack_t *aux_two = NULL;

	aux = *stack;

	while (aux != NULL)
	{
		aux_two = aux->next;
		free(aux);
		aux = aux_two;
	}
}
