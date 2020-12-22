#include "monty.h"
stainst_t stainst;
/**
 * _atoi - transform a char in an integer
 * @s: string to convert in integers
 * Return: value
 */
int _atoi(char *s)
{
	int value, i, neg;

	i = 0;
	value = 0;
	neg = -1;
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
		value = (value * 10) - (s[i++] - '0');
	return (value * neg);
}
/**
 * _strcmp - function to compare two strings
 * @s1: string compared
 * @s2: string compared
 * Return:  0 if they are the same and -1 if not
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
/**
 * _strlen - function to know the length of the string
 * @s: string
 * Return:  length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
 * _strcpy - copies string pointed to by src
 * @dest: character pointer
 * @src: character source
 * Return: the pointer to des
 */
char *_strcpy(char *dest, char *src)
{
	int i;  for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}   dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function concatenates two strings
 * @dest: string of destination
 * @src: string of source
 * Return:  dest - strings concatenated
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int x = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[x] != '\0')
	{
		dest[i] = src[x];
		x++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncmp - function to compare two strings with a certain amount of bytes
 * @s1: string compared
 * @s2: string compared
 * @len: amount of bytes to be compare
 * Return: 0 if they are the same and -1 if not
 */

int _strncmp(char *s1, char *s2, int len)
{
	int a = 0;

	while (a < len)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
int check_number(char *token_two, unsigned int line_number)
{
	unsigned int i;
	int flag;
	int number;

	for (i = 0; token_two[i] != '\0'; i++)
	{
		if (token_two[i] < 48 || token_two[i] > 57)
		{
			flag = 1;
		}
		else
		{
			flag = 2;
		}
	}
	if (flag == 1)
	{
		number = _atoi(token_two);
	}
	if (flag == 2)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
return (number);
}
void free_memory(stack_t **stack)
{
	stack_t *aux = NULL;
	stack_t *aux_two = NULL;

	aux = *stack;

	while (aux != NULL)
	{
		aux_two = aux->next;
		free(aux);
		aux = aux_two;
	}
}