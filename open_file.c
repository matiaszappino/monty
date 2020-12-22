#include "monty.h"
void open_file(char *argv[], stack_t **stack)
{
    size_t size = 0;
    ssize_t n;
    FILE *fp;
    unsigned int line_number = 0;
    char *token = NULL;
    char *token_two = NULL;
    char *buffer = NULL;
    int free_count = 0;

    if (!argv[1])
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        free_memory(stack);
        /**free(buffer);**/
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((n = getline(&buffer, &size, fp)) != EOF)
    {
        while(buffer[0] == 32)
        {
            free_count++;
            buffer++;
        }
        if (buffer[0] == '\n' || buffer[0] == '\0')
        {
            continue;
        }

        token = strtok(buffer, DEL);
        token_two = strtok(NULL, DEL);
        line_number++;

        printf("Token %s\n", token);
        printf("Token 2 %s\n", token_two);

        if ((strcmp(token, "push") == 0) && token_two != NULL)
            check_number(token_two, line_number);
        if (strlen(token) != 0 && token[0] != '#')
            functions(token, stack, line_number);
    }
    while (free_count > 0)
    {
        buffer--;
        free_count--;
    }
    free_memory(stack);
    free(buffer);
    fclose(fp);
    return;
}