#include "monty.h"

/**
 * main - interpret and execute Monty ByteCodes files
 * @argc: number of argument
 * @argv: arguments
 *
 * Return: 0 in sucess
 */
int main(int argc, char *argv[])
{
	unsigned int line;
	FILE *fp;
	char buffer[1024], *opcode, *integer;
	stack_t *stack;

	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = 1;
	stack = NULL;
	while (!feof(fp))
	{
		memset(buffer, 0, sizeof(buffer));
		if (fgets(buffer, sizeof(buffer), fp) == NULL)
			break;
		opcode = strtok(buffer, " \n");
		if (opcode == NULL)
			continue;
		if (strcmp(instr[0].opcode, opcode) == 0)
		{
			integer = strtok(NULL, " \n");
			if (integer == NULL || !isint(integer))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			instr[0].f(&stack, atoi(integer));
		}
		else if (strcmp(instr[1].opcode, opcode) == 0)
		{
			instr[1].f(&stack, 0);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
		}
		line++;
	}
	free_stack_int(stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
