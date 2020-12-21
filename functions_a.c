#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: head
 * @n: n
 * Return: Always EXIT_SUCCESS.
 */
void push_function(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
    stack_t *aux = NULL;

    if (!stack || !line_number)
    {
        printf("L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));

    if (!new)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = line_number;
    new->next = *stack;
    new->prev = NULL;
    if (new->next != NULL)
        (new->next)->prev = new;
    *stack = new;
}
/**
 * print_dlistint - function that prints all the elements of a dlistint_t list.
 * @h: h
 * Return: The number of nodes.
 */
void pall_function(stack_t **stack, unsigned int line_number) 
{
    (void) line_number;
    stack_t *aux;

    if (!stack)
        return;
    

    aux = *stack;

    while (aux)
    {   
        printf("%i\n", aux->n);
        aux = aux->next;
    }
}
/**
 * print_dlistint - function that prints all the elements of a dlistint_t list.
 * @h: h
 * Return: The number of nodes.
 */
void pint_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack)
    {
        printf("L%i: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }

    aux = *stack;
    printf("%i\n", aux->n);
}
void pop_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack)
    {
        printf("L%i: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }

    aux = *stack;
    *stack = (*stack)->next;
    free(aux);

}