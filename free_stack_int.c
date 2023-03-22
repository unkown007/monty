#include "monty.h"

/**
 * free_stack_int - frees a stack_t stack
 * @stack: pointer to top  of the stack
 */
void free_stack_int(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
