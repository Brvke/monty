#include "monty.h"
/**
 * strctarray -  convnverts and sends opcode to
 *		appropirate function
 * @TOP: top of stack pointer
 * @fileop: organized order from interpreter
 * @line_count: count of the current line
 * @n: value at a node
 *
 * Return: always return 0 if sucess
 *
*/
int strctarray(stack_t **TOP, char *fileop, unsigned int line_count, int n)
{
	int i, struct_size;
	instruction_t myfunctions[] = {{"pall", pall},
					{"pint", pint},
					{"pop", pop},
					{"swap", swap},
					{"add", add},
					{"sub", sub},
					{"div", _div},
					{"mul", mul},
					{"mod", mod},
					{"pchar", pchar},
					{"pstr", pstr},
					{"rotr", rotr},
					{"rotl", rotl}};

	if (strlen(fileop) <= 2)
		return (1);
	struct_size = sizeof(myfunctions) / sizeof(myfunctions[0]);
	if (strcmp(fileop, "push") == 0)
	{
		push(TOP, line_count, n);
		return (0);
	}
	else if (strcmp(fileop, "nop") == 0)
		return (0);
	for (i = 0 ; i < struct_size ; i++)
	{
		if (strcmp(fileop, myfunctions[i].opcode) == 0)
		{
			myfunctions[i].f(TOP, line_count);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, fileop);
	freestack(*TOP);
	exit(EXIT_FAILURE);
}
