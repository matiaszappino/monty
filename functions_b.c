#include "monty.h"
/**
 * add_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void add_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !*stack || !(*stack)->next)
	{
	fprintf(stderr, "L%i: can't add, stack too short", line_number);
	exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->n = (((*stack)->n) + (aux->n));
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev = *stack;
	free(aux);
}
/**
 * nop_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void nop_function(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
/**
 * sub_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void sub_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->n = ((aux->n) - ((*stack)->n));
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev = *stack;
	free(aux);
}
/**
 * div_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void div_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !*stack || !(*stack)->next)
	{
	fprintf(stderr, "L%i: can't add, stack too short", line_number);
	exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->n = (((*stack)->n) / (aux->n));
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev = *stack;
	free(aux);
}
/**
 * mul_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void mul_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->n = (((*stack)->n) * (aux->n));
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev = *stack;
	free(aux);
}
