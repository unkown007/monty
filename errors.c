#include "monty.h"

/**
 * push_error - prints msg of push error
 * @fp: file pointer
 * @stack: pointer to the top of stack
 * @line_number: number where the error occured
 */
void push_error(FILE *fp, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n",
			line_number);
	fclose(fp);
	free_stack_int(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - prints msg of instruction error
 * @fp: file pointer
 * @stack: pointer to the top of stack
 * @opcode: failed command
 * @line_number: number where the error occured
 */
void ins_error(FILE *fp, stack_t *stack, char *opcode, int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	fclose(fp);
	free_stack_int(stack);
	exit(EXIT_FAILURE);
}
