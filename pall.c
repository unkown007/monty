#include "monty.h"

/**
 * pall - prints all elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: unused attribute/ no meaning to pall
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *node;

	node = *stack;
	while (node != NULL)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
