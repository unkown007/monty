#include "monty.h"

/**
 * rotl - rotates the stack to top
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *top;
	stack_t *node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node = top = *stack;
		while (node->next)
			node = node->next;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		node->next = top;
		top->prev = node;
		top->next = NULL;
	}
}
