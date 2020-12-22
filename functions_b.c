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
	stack_t *aux_two = NULL;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!*stack || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux_two = *stack;
	aux_two = aux_two->next;
	aux_two->n = ((aux->n) + (aux_two->n));
	*stack = aux_two;
	aux_two->prev = NULL;
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
	stack_t *aux_two = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux_two = *stack;
	aux_two = aux_two->next;
	aux_two->n = (aux_two->n) - (aux->n);
	*stack = aux_two;
	aux_two->prev = NULL;
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
	stack_t *aux_two = NULL;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!*stack || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux_two = *stack;
	aux_two = aux_two->next;
	aux_two->n = ((aux->n) / (aux_two->n));
	*stack = aux_two;
	aux_two->prev = NULL;
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
	stack_t *aux_two = NULL;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux_two = *stack;
	aux_two = aux_two->next;
	aux_two->n = ((aux->n) * (aux_two->n));
	*stack = aux_two;
	aux_two->prev = NULL;
	free(aux);
}
