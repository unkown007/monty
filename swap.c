#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top element of the stack
 * @line_number: number of the line in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = (*stack)->next;
	(*stack)->next = node->next;
	if (node->next != NULL)
		node->next->prev = *stack;
	node->prev = (*stack)->prev;
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}
