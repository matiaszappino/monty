#include "monty.h"
void add_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack || !(*stack)->next)
    {
        printf("L%i: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    aux = (*stack)->next;
    (*stack)->n = (((*stack)->n) + (aux->n));
    (*stack)->next = (*stack)->next->next;
    (*stack)->next->prev = *stack;
    free (aux);
}
void nop_function(stack_t **stack, unsigned int line_number)
{
    (void)*stack;
    (void)line_number;
    return;
}
void sub_function(stack_t **stack, unsigned int line_number)
{
     stack_t *aux;

    if (!stack || !*stack || !(*stack)->next)
    {
        printf("L%i: can't sub, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    aux = (*stack)->next;
    (*stack)->n = ((aux->n) - ((*stack)->n));
    (*stack)->next = (*stack)->next->next;
    (*stack)->next->prev = *stack;
    free (aux);
}
void div_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack || !(*stack)->next)
    {
        printf("L%i: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    aux = (*stack)->next;
    (*stack)->n = (((*stack)->n) / (aux->n));
    (*stack)->next = (*stack)->next->next;
    (*stack)->next->prev = *stack;
    free (aux);
}
void mul_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux;

    if (!stack || !*stack || !(*stack)->next)
    {
        printf("L%i: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    aux = *stack;
    aux = (*stack)->next;
    (*stack)->n = (((*stack)->n) * (aux->n));
    (*stack)->next = (*stack)->next->next;
    (*stack)->next->prev = *stack;
    free (aux);
}