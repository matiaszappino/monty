#include "monty.h"
stainst_t stainst;
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: head
 * @n: n
 * Return: Always EXIT_SUCCESS.
 */
void push_function(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
    (void) line_number;

    if (!stack)
    {
        exit(EXIT_FAILURE);
        free_memory(stack);
    }
    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr,"Error: malloc failed\n");
        free_memory(stack);
        exit(EXIT_FAILURE);
    }
    new->n = stainst.number;
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
    stack_t *aux;
    (void) line_number;

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
        fprintf(stderr, "L%i: can't pint, stack empty", line_number);
        /**free_memory(stack);**/
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    printf("%i\n", aux->n);
}
/**
 * pop_function - function that prints all the elements of a dlistint_t list.
 * @stack: stack
 * @line_number: line_number
 * Return: The number of nodes.
 */
void pop_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%i: can't pop an empty stack", line_number);
        /**free_memory(stack);**/
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    *stack = (*stack)->next;
    free(aux);
}
void swap_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
        /**free_memory(stack);**/
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    aux = (*stack)->next;
    (*stack)->prev = (*stack)->next;
    (*stack)->next =aux->next;
    aux->prev = NULL;
    if (aux->next)
        aux->next->prev = *stack;
    aux->next = *stack;
    *stack = (*stack)->prev;
}
