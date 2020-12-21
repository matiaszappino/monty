#include "monty.h"
stainst_t stainst;
void functions(char *token, char *token_two, stack_t **stack, unsigned int line_number)
{
    unsigned int i = 0;
    int number;

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
        /**{"mod", mod_function},
        {"pchar", pchar_function},
        {"pstr", pstr_function},
        {"rotl", rotl_function},
        {"rotr", rotr_function},
        {"stack", stack_function},
        {"queue", queue_function},**/
        {NULL, NULL}
    };
    if (token_two != NULL)
    {
        number = check_number(token_two, line_number);
        stainst.number = number;
    }
    while (op_func[i].opcode != NULL)
	{
		if (_strcmp(token, op_func[i].opcode) == 0 &&
		    (_strlen(token) == _strlen(op_func[i].opcode)))
            {
			    op_func[i].f(stack, line_number);
            }
        else if (op_func[i].opcode == NULL)
        {
            fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
            free(stack);
            free(token);
            free(token_two);
            exit(EXIT_FAILURE);
        }
		i++;
    }
}
void stack_init(stack_t **head)
{
	*head = NULL;
	stainst.stack = head;
}