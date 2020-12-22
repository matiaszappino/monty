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

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->n = (((aux->n) % (*stack)->n));
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev = *stack;
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
    (void)stack;
    (void)line_number;
    return;
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotl_function(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    return;
}
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr_function(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    return;
}