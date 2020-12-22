#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#define BUFFSIZE 1024
#define DEL " \n\t "
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct stainst_s - opcode and its function
 * @stack: double pointer to stack_t struct
 * @inst: double pointer to instruction_t struct
 * @number: number
 *
 * Description: double pointers
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stainst_s
{
	stack_t **stack;
	instruction_t **inst;
	int number;
	char *token;
} stainst_t;
extern stainst_t stainst;

int open_file(char *argv[], stack_t **stack);
void functions(char *token, stack_t **stack, unsigned int line_number);
void push_function(stack_t **stack, unsigned int line_number);
void pall_function(stack_t **stack, unsigned int line_number);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number);
void swap_function(stack_t **stack, unsigned int line_number);
void add_function(stack_t **stack, unsigned int line_number);
void nop_function(stack_t **stack, unsigned int line_number);
void sub_function(stack_t **stack, unsigned int line_number);
void div_function(stack_t **stack, unsigned int line_number);
void mul_function(stack_t **stack, unsigned int line_number);
void process_file(stack_t **stack, FILE *fp_two);
void stack_init(stack_t **head);
void free_memory(stack_t **stack);
void check_number(char *token_two, unsigned int line_number);
void if_statements(stack_t **stack, char *token, char *token_two, unsigned int line_number);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int len);
#endif
