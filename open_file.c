#include "monty.h"
void open_file(char *argv[], stack_t **stack)
{
    char *buffer = NULL;
    size_t size = 0;
    ssize_t n;
    FILE *fp;
    unsigned int line_number = 0;
    char *token = NULL;
    char *token_two = NULL;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((n = getline(&buffer, &size, fp)) != -1)
    {
        while(buffer[0] == 32)
        {
            buffer++;
        }
        if (buffer[0] == '\n' || buffer[0] == '\0')
            continue;
        token = strtok(buffer, DEL);
        token_two = strtok(NULL, DEL);
        line_number++;
        functions(token, token_two, stack, line_number);
        token = NULL;
        token_two = NULL;
        /**free(buffer);**/
    }
    free_memory(stack);
    fclose(fp);
    free(buffer);
    free(token);
    free(token_two);
}