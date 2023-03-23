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
	if (argc == 2)
		handle_command(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * handle_command - read and processes the file
 * @argv: name of the file
 */
void handle_command(char *argv)
{
	int line_number = 0, res  = 0;
	char *arg = NULL, *item = NULL;
	char line[4098];
	stack_t *stack = NULL;
	FILE *fp;

	fp = fopen(argv, "r");
	if (fp)
	{
		while (!feof(fp))
		{
			memset(line, 0, sizeof(line));
			if (fgets(line, sizeof(line), fp) == NULL)
				break;
			line_number++;
			arg = strtok(line, " \n\t\r");
			if (arg == NULL)
				continue;
			else if (*arg == '#')
				continue;
			item = strtok(NULL, " \n\t\r");
			res = get_opc(&stack, arg, item, line_number);
			if (res == 1)
				push_error(fp, stack, line_number);
			else if (res == 2)
				ins_error(fp, stack, arg, line_number);
		}
		free_stack_int(stack);
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_opc - look for the opcode and execute
 * @stack: pointer to the top of the stack
 * @arg: command parameter
 * @item: parameter
 * @line: line number
 *
 * Return: number
 */
int get_opc(stack_t **stack, char *arg, char *item, int line)
{
	int i = 0;

	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL},
	};

	while (instr[i].opcode)
	{
		if (!strcmp(arg, instr[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (isint(item))
					value = atoi(item);
				else
					return (1);
			}
			instr[i].f(stack, (unsigned int) line);
			break;
		}
		i++;
	}
	if (!instr[i].opcode)
		return (2);

	return (0);
}
