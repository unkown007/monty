#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
