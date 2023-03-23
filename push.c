#include "monty.h"

int value;
int stack_flag;
/**
 * push - pushes an integer element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: number to push
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *node;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	if (stack_flag)
	{
		new->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new;
		}
		else
		{
			node = *stack;
			while (node->next)
				node = node->next;
			node->next = new;
			new->prev = node;
		}
	}
}

/**
 * _stack - sets the stack flag to 1
 * @stack: parameter
 * @line_number: parameter
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	stack_flag = 1;
}

/**
 * _queue - sets the stack flag to 0
 * @stack: parameter
 * @line_number: parameter
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	stack_flag = 0;
}
