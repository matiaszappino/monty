#include "monty.h"
stainst_t stainst;
int main(int argc, char *argv[])
{
    stack_t *head;
    stack_init(&head);
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv, &head);
    exit(EXIT_SUCCESS);
}