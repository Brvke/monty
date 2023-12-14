#include "monty.h"
/**
 * checkint - a funciton to check if psuh recives
 *
 * @TOP: top of stack pointer
 * @command: string that is a modifeid value from interpreter line
 * @i: location counter on command string
 * @line_count: count of current line
 *
 * Return: returns 0 if sucess
 *
*/
int checkint (stack_t *TOP, char *command, int i, unsigned int line_count);
int checkint (stack_t *TOP, char *command, int i, unsigned int line_count)
{
	int n;
	char *endptr;

	i++;
	if (isdigit(command[i]) || command[i] == '-' || command[i] == '+')
		n = (int) strtol(&command[i], &endptr, 10);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		freestack(TOP);
		exit(EXIT_FAILURE);
	}
	if (endptr[0] != 0 && endptr[0] != 10)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		freestack(TOP);
		exit(EXIT_FAILURE);
	}

	return (n);
}
/**
 * cmd2struct - converts command to final order string fileop
 *
 * @TOP:pointer totop of string
 * @command:a modified verison of line string
 * @fileop:a final verion of the command
 * @line_count: count of the current line
 *
 * Return: returns 0 if sucess
*/
int cmd2struct(stack_t *TOP, char *command,
		char *fileop, unsigned int line_count)
{
	int i, j, n;

	n = i = j = 0;
	if (command == NULL)
		exit(0);
	if (command[0] == '#')
		return (1);
	while (command[i] != ' ' && command[i] != '\0' && command[i] != '$')
	{
		fileop[i] = command[i];
		i++;
	}
	if (strcmp(fileop, "push") == 0)
		n = checkint(TOP, command, i, line_count);
	return (n);
}
