#include "monty.h"
stainst_t stainst;
/**
 * functions - adds a new node at the beginning of a dlistint_t list.
 * @token: token
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void functions(char *token, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t op_func[] = {
	{"push", push_function},
	{"pall", pall_function},
	{"pint", pint_function},
	{"pop", pop_function},
	{"swap", swap_function},
	{"add", add_function},
	{"nop", nop_function},
	{"sub", sub_function},
	{"div", div_function},
	{"mul", mul_function},
	/**
     * {"mod", mod_function},
     * {"pchar", pchar_function},
     * {"pstr", pstr_function},
     * {"rotl", rotl_function},
     * {"rotr", rotr_function},
     * {"stack", stack_function},
     * {"queue", queue_function},
     */
	{NULL, NULL}
	};
	while (op_func[i].opcode != NULL)
	{
		if (strcmp(token, op_func[i].opcode) == 0)
		{
			stainst.token = token;
			op_func[i].f(stack, line_number);
			stainst.token = NULL;
			return;
		}
		i++;
	}
	if (strlen(token) != 0 && token[0] != '#')
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
}
/**
 * stack_init - function that initialates the stack
 * @head: head
 * Return: void
 */
void stack_init(stack_t **head)
{
	*head = NULL;
	stainst.stack = head;
}
