#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *top;
	stack_t *node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node = top = *stack;
		while (node->next)
			node = node->next;
		node->next = top;
		top->prev = node;
		node->prev->next = NULL;
		node->prev = NULL;
		*stack = node;
	}
}
