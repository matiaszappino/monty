#include "monty.h"
void open_file(char *argv[], stack_t **stack)
{
    char *buffer = NULL;
    size_t size = 0;
    ssize_t n;
    FILE *fp;
    /**char **tokens = NULL;**/
    char *token = NULL;
    char *token_two = NULL;
    unsigned int i = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*tokens = malloc(sizeof(char *) * BUFFSIZE);
	if (!tokens)
	    return;**/

    while ((n = getline(&buffer, &size, fp)) != -1)
    {
        /**printf("This is buffer: %s\n", buffer);**/
        token = strtok(buffer, DEL);
        token_two = strtok(NULL, DEL);
        /**printf("This is token: %s\n", token);
            tokens[i] = token;
            printf("This is tokens[i]: %s\n", tokens[i]);
            i++;
            token = strtok(NULL, DEL);**/
        functions(token, token_two, buffer, stack);
        token = NULL;
        token_two = NULL;
    }
}