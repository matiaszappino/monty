#include "monty.h"
stainst_t stainst;
/**
 * push_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void push_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stainst.token == NULL || stack == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
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
 * pall_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void) line_number;

	aux = *stack;
	while (aux)
	{
		printf("%i\n", aux->n);
		aux = aux->next;
	}
}
/**
 * pint_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pint_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	printf("%i\n", aux->n);
}
/**
 * pop_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}
/**
 * swap_function - adds a new node at the beginning of a dlistint_t list.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = aux->next;
	aux->prev = NULL;
	if (aux->next)
		aux->next->prev = *stack;
	aux->next = *stack;
	*stack = (*stack)->prev;
}
