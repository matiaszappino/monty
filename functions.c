#include "monty.h"
stainst_t stainst;
void functions(char *token, char *token_two, stack_t **stack, unsigned int line_number)
{
    unsigned int i = 0;
    unsigned int entero;

    instruction_t op_func[] = {
        {"push", push_function},
        {"pall", pall_function},
        {"pint", pint_function},
        {"pop", pop_function},
        {"swap", swap_function},
        {"add", add_function},
        {"nop", nop_function},
        {"sub", sub_function},
        /**{"div", div_function},
        {"mul", mul_function},
        {"mod", mod_function},
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
        entero = _atoi(token_two);
        stainst.number = entero;
    }
    while (op_func[i].opcode != NULL)
	{
		if (_strcmp(token, op_func[i].opcode) == 0 &&
		    (_strlen(token) == _strlen(op_func[i].opcode)))
            {
			    op_func[i].f(stack, line_number);
			    /**if (status != 0)
				    return (0);
			    else if (status == 1)
				    return (1);**/
            }
		i++;
    }
    return;
}
void stack_init(stack_t **head)
{
	*head = NULL;
	stainst.stack = head;
}