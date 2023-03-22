#include "monty.h"

/**
 * isint - checks if a string an integer number
 * @str: pointer to the string
 *
 * Return: 1 if is int, 0 otherwise
 */
int isint(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	for (; *str != '\0' && *str != '\n'; str++)
		if (*str < 48 || *str > 57)
			return (0);
	return (1);
}
