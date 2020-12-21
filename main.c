#include "monty.h"
int main(int argc, char *argv[])
{
    stack_t *head;
    stack_init(&head);
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv, &head);
    return (0);
}