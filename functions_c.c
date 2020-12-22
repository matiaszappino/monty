#include "monty.h"
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void mod_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;
    stack_t *aux_two = NULL;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
    if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux_two = *stack;
	aux_two = aux_two->next;
	aux_two->n = ((aux_two->n) % (aux->n));
	aux_two->prev = NULL;
	*stack = aux_two;
	free(aux);
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pchar_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
    if (((*stack)->n >= 65 && (*stack)->n <= 90) || ((*stack)->n >= 97 && (*stack)->n <= 120))
    {
        aux = *stack;
	    putchar(aux->n);
        putchar('\n');
    }
	else
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
    }
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pstr_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;
    (void) line_number;

	if (!*stack)
	{
        putchar('\n');
		return;
	}
    aux = *stack;
    while (aux)
    {
        if (aux->n != 0 && isascii(aux->n))
        {
            putchar(aux->n);
            aux = aux->next;
        }
        else
        {
            break;
        }
    }
    putchar('\n');
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotl_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;
    stack_t *aux_two = NULL;
    (void) line_number;

    if (!*stack || !(*stack)->next)
	{
		return;
	}
    aux_two = *stack;
	aux = (*stack)->next;
    aux->prev = NULL;
     while (aux_two->next)
    {
        aux_two = aux_two->next;
    }
    aux_two->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = aux_two;
    *stack = aux;
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr_function(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;
    (void) line_number;

    if (!*stack || !(*stack)->next)
	{
		return;
	}
    aux = *stack;
    while (aux->next)
		aux = aux->next;
	aux->next = *stack;
	aux->prev->next = NULL;
	aux->prev = NULL;
	(*stack)->prev = aux;
	(*stack) = aux;
}