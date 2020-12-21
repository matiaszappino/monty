#include "monty.h"
void functions(char *token, char *token_two, char *buffer, stack_t **stack)
{
    unsigned int i = 0;
    unsigned int line_number;
    /**int status;**/
    char *tokenword = NULL;

    
    /**printf("Token %s\n", token);
    printf("Token %s\n", token_two);
    printf("buffer %s\n", buffer);**/

    instruction_t op_func[] = {
        {"push", push_function},
        {"pall", pall_function},
        {"pint", pint_function},
        {"pop", pop_function},
        /**{"swap", swap_function},
        {"add", add_function},
        {"nop", nop_function},
        {"sub", sub_function},
        {"div", div_function},
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

    /**printf("Token %s\n", token);
    printf("Token %s\n", token_two);**/

    if (token_two != NULL)
        line_number = _atoi(token_two);

    /**printf("line_number %i\n", line_number);**/
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
    /**free(token);**/
    /**free(token_two);**/
    /**free(buffer);**/
    return;
}