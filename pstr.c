#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *node = *stack;

	while (node)
	{
		if (node->n == 0)
			break;
		if (node->n >= 32 && node->n <= 127)
			fprintf(stdout, "%c", node->n);
		else
			break;
		node = node->next;
	}
	fprintf(stdout, "\n");
}
